//Converting BinarySearchTree to Linked List

template<typename T>

class Node
{
	public:
		T data;
		Node<T> *next;

		Node(T data)
		{
			this -> data = data;
	    		this -> next = NULL;
		}
};

class NodePair
{
	public:
		Node<T>*head;
		Node<T>*tail;

};
NodePair<int> helper(BinaryTreeNode<int>* root)
{
	if(root == NULL)
	{
		NodePair<int> np;
		np.head = NULL;
		np.tail = NULL;
		
		return np;
	}

	NodePair<int>l = helper(root -> left);
	NodePair<int>r = helper(root -> right);

	Node<int>*n = Node<int>(root -> data);

	if(l.tail != NULL)
		l.tail -> next = n;
	n -> next = r.head;
	
	NodePair<int> np;

	if(l.head != NULL)
		np.head = l.head;
	else
		np.head = n;
	if(r.tail != NULL)
		np.tail = r.tail;
	else
		np.tail = n;

	return np;

}

Node<int>BSTtoLL(BinaryTreeNode<int>* root)
{
	NodePair<int>np = helper(root);
	return np.head;
}


