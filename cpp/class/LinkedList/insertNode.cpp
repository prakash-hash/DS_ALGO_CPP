#include <iostream>
using namespace std;

Node *insertNode(Node *head, int i, int data)
{
	Node *newNode = new Node(data);
	Node *temp = head;
	int count = 0;
	if(i == 0)
	{
		newNode -> next = head;
		head = newNode;
	
		return head;
	}

	while(temp != NULL && count < i-1)
	{
		temp = temp -> next;
		count++;
	}

	if(temp != NULL)
	{
		newNode -> next = temp -> next;
		temp -> next = newNode;
	}

	return head;
}
