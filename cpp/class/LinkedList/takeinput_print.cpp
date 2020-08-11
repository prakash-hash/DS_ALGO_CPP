#include <iostream>
#include "Node.cpp"
#include "printLLf.cpp"
#include "takeinputLL.cpp"
#include "takeinputLL2.cpp"
#include "printiLL.cpp"
#include "insertNode.cpp"
#include "mergesort.cpp"

using namespace std;

int main()
{
	int index = 0;
	int data = 0;
	//Node *head = takeinput();
	cout<<"Enter List\n";
	Node *head = takeinput2();
	print(head);
	//cin >> index;
	//cin >> data;
	//head = insertNode(head, index, data);
	//print(head);
	//printIthNode(head,5);
	Node *newhead = NULL;
	newhead = mergeSort(head);
	print(newhead);
}
