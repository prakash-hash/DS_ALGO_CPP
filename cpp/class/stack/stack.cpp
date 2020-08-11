#include <iostream>
using namespace std;
#include "stack_array.cpp"
int main()
{
	stack_arr stack1(5);	
	cout<<stack1.IsEmpty()<<endl;
	stack1.push(10);
	stack1.push(20);
	stack1.push(30);
	stack1.push(40);
	stack1.push(50);
	stack1.push(60);
	stack1.print_stack();
	cout<<stack1.pop()<<endl;
	stack1.print_stack();
	cout<<stack1.size()<<endl;
	cout<<stack1.IsEmpty()<<endl;
	cout<<stack1.top()<<endl;
}
