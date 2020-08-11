#include <iostream>
using namespace std;

#define SQUARE(x) x*x
bool flag = true;
void fun()
{
	flag = false;
	cout<<"flag:"<<flag<<endl;
}
int main(){
    // int x = 36 / SQUARE(6);
    // cout << x<<SQUARE(6);
	fun();
    return 0;
}
