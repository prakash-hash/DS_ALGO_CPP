#include <isotream>
uisng namespace std;

int length(Node *head)
{
	int count = 0;
	while(head != NULL)
	{
		count++;
		head = head -> next;
	}
	return count;
}
