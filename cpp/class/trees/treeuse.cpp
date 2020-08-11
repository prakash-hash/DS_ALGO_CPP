#include <iostream>
#include "treenode.h"
#include <queue>
using namespace std;

treenode<int> *takeInputLevel()
{
	int rootData;
        cout<<"Enter data"<<endl;
        cin>>rootData;
        treenode<int> *root = new treenode<int>(rootData);
	
	queue<treenode<int> *> pendingnode;
	pendingnode.push(root);

	while(pendingnode.size() != 0)
	{
        	treenode<int> *front = pendingnode.front();
		pendingnode.pop();
		
		int numChild;
		cout<<"Enter number of children of "<< front -> data<<endl;
		cin>>numChild;

		for(int i = 0; i < numChild; i++)
		{
			cout<<"Enter "<<i<<"th child of "<<front -> data<<endl;
			int childData;
			cin >> childData;
			treenode<int> *child = new treenode<int>(childData);

			front -> children.push_back(child);
			pendingnode.push(child);
		}
	}

	return root;
}




treenode <int> *takeInput()
{
	int rootData;
	cout<<"Enter data"<<endl;
	cin>>rootData;
	treenode<int> *root = new treenode<int>(rootData);
	
	int n;
	cout<<"Enter number of children of "<<rootData<<endl;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		treenode<int> *child = takeInput();
		root -> children.push_back(child);
	}
	
	return root;
}

void PrintTreeLevel(treenode<int>* root)
{
	queue<treenode<int> *> pendingnodes;
	pendingnodes.push(root);

	while(pendingnodes.size() != 0)
	{
		treenode<int> *front = pendingnodes.front();
		pendingnodes.pop();
		cout<<front -> data<<":";

		for(int i = 0; i < front -> children.size(); i++)
		{
			cout<< front -> children[i] -> data<<',';
			pendingnodes.push(front -> children[i]);
		}
		cout<<endl;


	}

}
void treeprint(treenode<int> *root)
{
	cout << root -> data <<':';

	for(int i = 0; i < root -> children.size(); i++)
                cout<<root -> children[i] -> data<<',';
        
	cout<<endl;
	
	for(int i = 0; i < root -> children.size(); i++)
		treeprint(root -> children[i]);
}

int sumNode(treenode<int> *root)
{
	int ans = root -> data;
	for(int i = 0; i < root -> children.size(); i++)
		ans += sumNode(root -> children[i]);
	return ans;
}

int countNode(treenode<int> *root)
{
	int ans = 1;
	for(int i = 0; i < root -> children.size(); i++)
		ans += countNode(root -> children[i]);
	return ans;
}

treenode<int> *maxNodeData(treenode<int> *root)
{
	if(root == NULL)
		return 0;
	static treenode<int> *maxNode = root;
	for(int i = 0; i < root -> children.size(); i++)
	{
		if(maxNode -> data < root -> children[i] -> data)
		{
			maxNode = root -> children[i];
		}
		maxNodeData(root -> children[i]);
	}
	return maxNode;
}

int height(treenode<int> *root)
{
	if(root == NULL)
		return 0;
	
	int maxheight = 1;
	int maxheight2 = 1;
	for(int i = 0; i < root -> children.size(); i++)
	{
		maxheight = 1 +  height(root -> children[i]);
		if(maxheight > maxheight2)
			{
				maxheight2 = maxheight;
				maxheight = 0;
			}
	}
		return maxheight2;                  
}
void printAtlevelK(treenode<int> * root, int k)
{
	if(k == 0)
	{
		cout<< root -> data <<" ";
		return;
	}

	for(int i = 0; i < root -> children.size(); i++)
	{
		printAtlevelK(root -> children[i],k-1);
	}
}
void preOrder(treenode<int> *root)
{
	cout<<root -> data <<" ";
	for(int i = 0; i < root -> children.size(); i++)
	{
		preOrder(root -> children[i]);
	}
}

int numLeafNodes(treenode<int >* root)
{
	if(root -> children.size() == 0)
	{
		cout<<root -> data<<" ";
		return 1;
	}

	int sum = 0;
	for(int i = 0; i < root -> children.size(); i++)
		sum += numLeafNodes(root -> children[i]);
	return sum;

	/*
	 //better solution
	 int sum = 1;
	 for(int i = 0; i < root -> children.size(); i++)
	 	sum += numLeafNodes(root -> children[i]);
	return sum;
	*/
}

void postOrder(treenode<int> *root)
{
	for(int i = 0; i < root -> children.size(); i++)
		postOrder(root -> children[i]);
	cout<< root -> data<<" ";
}

bool containsX(treenode<int>* root, int x) 
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(root -> data == x)
        return 1;
    for(int i = 0; i < root -> children.size(); i++)
    	 containsX(root -> children[i],x);
}

//10 3 20 30 40 2 40 50 0 0 0 0

int main()
{
	/*
	treenode<int> *root = new treenode<int>(10);
	treenode<int> *node1 = new treenode<int>(20);
	treenode<int> *node2 = new treenode<int>(30);

	root -> children.push_back(node1);
	root -> children.push_back(node2);
	*/
	
	treenode<int> *root = takeInputLevel();
	PrintTreeLevel(root);
	cout<<sumNode(root)<<endl;	
	cout<<countNode(root)<<endl;	
	cout<<maxNodeData(root) -> data <<endl;
	cout<<height(root)<<endl;
	printAtlevelK(root,2);
	cout<<"\n"<<numLeafNodes(root)<<endl;
	preOrder(root);
	cout<<endl;
	postOrder(root);
	//delete root;
	//postOrder(root);
	cout<<containsX(root,50)<<endl;
}

	
	
