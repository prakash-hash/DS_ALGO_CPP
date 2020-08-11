BinaryTreeNode<int>* ArrToBST(int *input, int startIndex, int endIndex)
{
	if(startIndex > endIndex)
		return NULL;
	int mid = (startIndex+endIndex)/2;
	
	BinaryTreeNode<int>*root = BinaryTreeNode<int>(input[mid]);

	root -> left = ArrToBST(input, startIndex, mid - 1);
	root -> right = ArrToBST(input, mid+1, endIndex);

	return root;

}
