#include <vector>
//Finding Path From root to Node of a Binary Tree

vector<int>* RootToNode(BinaryTreeNode<int>* root, int data)
{
	if(root == NULL)
		return NULL;
	if(root -> data == data)
	{
		vector<int>* output = new vector<int>();
		output->push_back(root -> data);
		return output;
	}

	vector<int>* left = RootToNode(root -> left,data);
	if(left != NULL)
	{
		left -> push_back(root -> data);
		return left;
	}

	vector<int>* right = RootToNode(root -> right,data);
	if(right != NULL)
	{
		right -> push_back(root -> data);	
		return right;
	}
	else
		return NULL;
}
