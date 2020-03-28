#include <cstring>
#include <iostream>
using namespace std;

int keypad(int num, string *output){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num == 0)
    {
        output[0] = "";
        return 1;
    }
    string keypad_words[10] = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    int last_digit = num%10;
    int smallnum = num/10;
    int k = 0;

    string input = keypad_words[last_digit];
   
    
    int smallsize = keypad(smallnum,output);

    string smalloutput[smallsize];
    for(int i = 0; i < smallsize; i++)
        smalloutput[i] = output[i];


    for(int i = 0; i < input.size(); i++)
        for(int j = 0; j < smallsize; j++)
            output[k++] = smalloutput[j] + input[i];

    return smallsize*input.size();
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
