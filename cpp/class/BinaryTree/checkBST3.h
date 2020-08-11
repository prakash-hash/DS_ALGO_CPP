int isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX)
{
	if(root == NULL)
		return true;

	if(root -> data < min || root -> data > max)
		return false;

	bool isleftOK = isBST3(root -> left, min, root -> data -1);
	bool isrightOK = isBST3(root -> right, root -> data, max);

	return isleftOK && isrightOK;
}
