#include <climits>

class stack_arr
{
	int *data;
	int nextIndex;
	int capacity;
	public:
		stack_arr(int size_of_stack)
		{
			data = new int[size_of_stack];
			nextIndex = 0;
			capacity = size_of_stack;
		}

		void push(int element)
		{
			if(nextIndex == capacity)
			{
				cout<<"Stack is full"<<endl;
				return;
			}
			data[nextIndex++] = element;
		}

		int pop()
		{
			if(nextIndex == 0)
			{
				cout<<"Stack is empty. Push some elements"<<endl;
				return INT_MIN;
			}
			else
				return data[--nextIndex];
		}

		int size()
		{
			return nextIndex;
		}

		int top()
		{
			return data[nextIndex-1];
		}

		bool IsEmpty()
		{
			/*
			if(nextIndex == 0)
				return true;
			return false;
			*/

			return nextIndex == 0;
		}

		void print_stack()
		{
			for(int i = 0; i < nextIndex; i++)
				cout<<data[i]<<" ";
			cout<<endl;
		}
};
