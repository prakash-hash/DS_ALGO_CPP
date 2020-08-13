#include <iostream>
#include <queue>
using namespace std;
#include "BinaryTreeNode.h"

/*#include "BinaryTreeNodeSum.h"
#include "BalanceCheck.h"
#include <bits/stdc++.h>
#include "checkBST.h"
#include "checkBST2.h"
#include "checkBST3.h"
*/
#include "RootToNodePath.h"

BinaryTreeNode<int> *takeinputLevelWise()
{
	int rootData;
	cout<<"Enter root Data"<<endl;
	cin>>rootData;

	if(rootData == -1)
		return NULL;

	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	
	queue<BinaryTreeNode<int> *> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0)
	{
		BinaryTreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		
		int leftChildData;
		cout<<"Enter Left Child of "<<front -> data<<endl;
		cin>>leftChildData;
		if(leftChildData != -1)
		{
			front -> left = new BinaryTreeNode<int>(leftChildData);
			pendingNodes.push(front -> left);
		}

		int rightChildData;
		cout<<"Enter right Child of "<<front -> data<<endl;
		cin>>rightChildData;
		if(rightChildData != -1)
		{
			front -> right = new BinaryTreeNode<int>(rightChildData);
			pendingNodes.push(front -> right);
		}
	}
	return root;
}

void print(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return;

	cout<<root -> data<<":";
	if(root -> left != NULL)
		cout<<'L'<<root -> left -> data<<" ";
	if(root -> right != NULL)
		cout<<'R'<<root -> right -> data;
	cout<<endl;
	print(root -> left);
	print(root -> right);
}

void printLevelWise(BinaryTreeNode<int> *root) {
    
    if(root == NULL || root -> data == -1)
        return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        cout<< front -> data<<":";
        pendingNodes.pop();
		
        if(front -> left != NULL)
        {
            cout<<"L:"<<front->left->data;
            pendingNodes.push(front -> left);
        }
	else
            cout<<"L:"<<-1;
		
            
        if(front -> right != NULL)
        {
            cout<<",R:"<<front->right->data;
            pendingNodes.push(front -> right);
	}
	else
		cout<<",R:"<<-1;
        cout<<endl;
    }

}

BinaryTreeNode<int> *takeinput()
{
	int rootData;
	cout<<"Enter Data"<<endl;
	cin>>rootData;

	if(rootData == -1)
		return NULL;

	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int> *leftchild = takeinput();
	BinaryTreeNode<int> *rightchild = takeinput();
	root -> left = leftchild;
	root -> right = rightchild;

	return root;
	
}

int numNodes(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return 0;
	return 1 + numNodes(root -> left) + numNodes(root -> right);
}

void inorder(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return;

	inorder(root -> left);
	cout<<root -> data<< " ";
	inorder(root -> right);
}

int height(BinaryTreeNode<int> *root){
	if(root == NULL)
		return 0;
	return 1 + max(height(root -> left),height(root -> right));
}

int diameter(BinaryTreeNode<int> *root){
	if(root == NULL)
		return 0;
	int treeHeight = height(root->left) + height(root -> right);
	int lDiameter = diameter(root -> left);
	int rDiameter = diameter(root -> left);
	
	return max(treeHeight, max(lDiameter, rDiameter));
}

pair<int, int>heightDiameter(BinaryTreeNode<int> *root){
	if(root == NULL)
	{
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}

	pair<int, int> lheightDiameter = heightDiameter(root -> left);
	pair<int, int> rheightDiameter = heightDiameter(root -> right);

	int lh = lheightDiameter.first;
	int rh = rheightDiameter.first;
	int ld = lheightDiameter.second;
	int rd = rheightDiameter.second;

	int height = 1 + max(lh,rh);
	int diameter = max(lh+rh, max(ld, rd));

	pair<int, int>p;
	p.first = height;
	p.second = diameter;

	return p;
	}

pair<int, int>minMax(BinaryTreeNode<int>* root){
	pair<int, int>p;
	p.first = INT8_MAX;
	p.second = INT8_MIN;

	if(root == NULL)
		return p;

	pair<int, int>lminMax = minMax(root -> left);
	pair<int, int>rminMax = minMax(root -> right);

	p.first =min(min(lminMax.first, rminMax.first), root -> data);
	p.second = max(max(lminMax.second, rminMax.second), root -> data);

	return p;
}

// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1
int main()
{
	/*BinaryTreeNode<int> *root = new BinaryTreeNode<int>(10);
	BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(20);
	BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(30);

	root -> left = node1;
	root -> right = node2;
	*/
	//BinaryTreeNode<int> *root = takeinput();
	BinaryTreeNode<int> *root = takeinputLevelWise();
	printLevelWise(root);
	cout<<"Num:"<<numNodes(root)<<endl;
	
	vector<int>*arr = RootToNode(root,13);

	for(int i = 0; i < arr -> size(); i++)
		cout<<arr ->at(i)<<" ";

}
