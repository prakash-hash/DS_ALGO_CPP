class isBSTreturn
{

	public:
		bool isBST;
		int minimum;
		int maximum;
};

isBSTreturn isBST2(BinaryTreeNode<int>* root)
{
	if(root == NULL)
	{
		isBSTreturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}

	
	isBSTreturn LOut = isBST2(root -> left);
	isBSTreturn ROut = isBST2(root -> right);

	int minimum = min(root -> data, min(LOut.minimum, ROut.minimum));
	int maximum = max(root -> data, max(LOut.maximum, ROut.maximum));

	
	isBSTreturn Output;
	Output.isBST = root -> data > LOut.maximum && root -> data <= ROut.minimum && LOut.isBST && ROut.isBST;
       	Output.minimum = minimum;
	Output.maximum = maximum;

	return Output;
}	

