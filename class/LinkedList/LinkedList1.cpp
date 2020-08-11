#include <iostream>
#include "Node.cpp"
using namespace std;

int main()
{
	Node n1(10);
	Node *Head = &n1;

	Node n2(20);
	n1.next = &n2;

	cout<<n1.data<<":"<<n2.data;
}
