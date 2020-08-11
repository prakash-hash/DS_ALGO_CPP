#include <iostream>
using namespace std;

class student
{
	private:
		int class_;
	public:
		int age;

		student(int a, int c)
		{
			age = a;
			class_ = c;
		};
		~student()
		{
		cout<<"Destructor called"<<endl;
}
		void display()
		{
			cout<<"Age:"<<age<<" "<<"class:"<<class_<<endl;
		}
};
