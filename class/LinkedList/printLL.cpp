#include <iostream>
#include "Node.cpp"
using namespace std;

void print(Node *head)
{
	if(head != NULL)
	{
		cout<< head -> data <<endl;
		print(head -> next);
	}
}

int main()
{
	Node n1(10);
	Node *head = &n1;
	Node n2(20);
	n1.next = &n2;
	Node n3(30);
	n2.next = &n3;
	Node n4(40);
	n3.next = &n4;
	Node n5(50);
	n4.next = &n5;
	
	print(head);
}
