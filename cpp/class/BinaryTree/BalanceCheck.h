#include<cstdlib>

pair<int, bool>Balanced(BinaryTreeNode<int> *root){
	if(root == NULL)
	{
		pair<int, bool>p;
		p.first = 0;
		p.second = true;

		return p;

	}

	
	pair<int, bool> a = Balanced(root -> left);
	pair<int, bool> b = Balanced(root -> right);	
	pair<int, bool> ans;
	ans.first = 1+max(a.first, b.first);

	if(a.second && b.second)
	{
		if(abs(a.first - b.first) <= 1)
			 ans.second = true;
		else
			 ans.second = false;
	}
	else
		ans.second = false;

	return ans;

}

