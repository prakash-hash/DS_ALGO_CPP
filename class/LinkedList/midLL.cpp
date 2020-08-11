#include <iostream>
using namespace std;

Node *midLL(Node *head)
{
	Node *slow = head;
	Node *fast = head;
	if(head == NULL ||head -> next == NULL)
		return head;
	while(fast -> next != NULL && fast -> next -> next != NULL)
	{
		fast = fast -> next -> next;
		slow = slow -> next;	
	}
	return slow;
}
