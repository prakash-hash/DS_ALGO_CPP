int sumofAllNodes(BinaryTreeNode<int> *root){
	if(root == NULL)
		return 0;
	return root -> data + sumofAllNodes(root -> left) + sumofAllNodes(root -> right);
}
