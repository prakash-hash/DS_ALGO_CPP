#include <iostream>
#include "student.cpp"
using namespace std;

int main()
{
	student s1(10,5);
	student s2(s1);
	student s3(15,10);
	s3 = s1;
	s1.display();
	s2.display();
	s3.display();
}
