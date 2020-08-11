#include <iostream>
using namespace std;

void printIthNode(Node *head, int i)
{
	int count = 0;
	Node *curr = head;
	while(curr != NULL)
	{
		if(count == i)
			cout<< curr -> data<<endl;
		count++;
		curr = curr -> next;
	}
}
