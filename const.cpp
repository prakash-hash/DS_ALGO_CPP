#include <iostream>
using namespace std;

int main()
{
    const int i = 10;  //must be initialised at the time of declaration
    // doing i++ or any change in value of i is not accepted
    int const m =10; // same as const int
    int j = 10;
    const int &k = j;
    
    //k++ is not allowed
    j++; //is allowed
    
    int const i2 = 10;
    //int &k2 = i2; not allowed cant assign address
    int const *p = &j;
    //(*p)++; not allowed
}
