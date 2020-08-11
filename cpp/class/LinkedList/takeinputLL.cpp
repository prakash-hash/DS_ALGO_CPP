#include <iostream>

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL;
	
	while(data != -1)
	{	
		Node *newNode = new Node(data);
		if(head == NULL)
			head = newNode;
		else
		{
			Node *temp = head;
			while(temp -> next != NULL)
				temp = temp -> next;
			temp -> next = newNode;
		}
		cin >> data;
	}

	return head;
}
