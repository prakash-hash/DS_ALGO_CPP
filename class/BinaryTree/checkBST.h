
int minimum(BinaryTreeNode<int> * root)
{
	if(root == NULL)
		return INT_MAX;
	return min(root -> data,min(minimum(root -> left), minimum(root -> right)));
}

int maximum(BinaryTreeNode<int>* root)
{
	if(root == NULL)
		return INT_MIN;
	return max(root -> data,max(maximum(root -> left), maximum(root -> right)));
}

bool isBST(BinaryTreeNode<int> *root)
{
	if(root == NULL)
		return true;

	int LminVal = maximum(root -> left);
	int RmaxVal = minimum(root -> right);

	return root -> data > LminVal && root -> data <= RmaxVal && isBST(root -> left) && isBST(root -> right);
}
