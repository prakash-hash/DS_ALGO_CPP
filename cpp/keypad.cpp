#include <cstring>
#include <iostream>
using namespace std;

int keypad(int num, string *output){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string input;
    switch(num%10)
    {
        case 0:
            input = "";
            return 1;
        case 1:
            input = "";
            return 1;
        case 2:
            input = "abc";
            break;
        case 3:
            input = "def";
            break;
        case 4:
            input = "ghi";
            break;
        case 5:
            input = "jkl";
            break;
        case 6:
            input = "mno";
            break;
        case 7:
            input = "pqrs";
            break;
        case 8:
            input = "tuv";
            break;
        case 9:
            input = "wxyz";
            break;
                
    }
    // if(num == 0 || num == 1)
    // {
    //     output[0] = "";
    //     return 1;
    // }
    int smallsize = input.size()*keypad(num/10,output);
    cout<<input<<endl;
    string new_string[smallsize];

    for(int i = 0; i <= smallsize - input.size(); i++)
    {    
        new_string[i] = output[i];
        cout<<"new_string : "<<i<<" : "<<new_string[i]<<endl;
    }
    int k = 0;

    for(int i = 0; i < input.size(); i++)
    {
        // output[k++] = new_string[i] + input[i];
        cout<<"before output :"<<i<<" : "<<output[i]<<"\n input :"<<i<<" : "<<input[i]<<endl;
        for(int j = 0; j < smallsize; j++)
        {
            output[k++] = new_string[j] + input[i];
        }
        cout<<"after output :"<<i<<" : "<<output[i]<<"\n k: "<<k<<endl;
    }
    cout<<"smallsize:"<<smallsize<<endl;
    return smallsize;
}



int main()
{
    int input;
    cin >> input;
    string* output = new string[1000]; 
    int count = keypad(input,output);
    for(int i = 0; i < count; i++)
        cout<<i<<":"<<output[i]<<endl;
    cout<<"len:"<<count<<endl;
}