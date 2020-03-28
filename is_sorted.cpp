#include <iostream>
using namespace std;

bool is_sorted(int a[],int size)
{
    if(size == 0 || size == 1)
        return true;
    if(a[0] > a[1])
        return false;
    return is_sorted(a+1,size-1);
}
int main()
{
    int a[5] = {10,20,30,60,50};
    cout<<is_sorted(a,5)<<endl;
}
