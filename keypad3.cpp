#include <cstring>
#include <iostream>
using namespace std;

string output = "";

void helper(string keypad_words[], int num, string output)
{
    if(num == 0)
    {
        cout<<output<<endl;
        return;
    }

    int last_digit = num%10;

    int len = keypad_words[last_digit].size();

    for(int i = 0; i < len; i++)
        helper(keypad_words, num/10, keypad_words[last_digit][i]+output);

}

void keypad(int num){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string keypad_words[10] = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    helper(keypad_words, num, string(""));
}



int main()
{
    int input;
    cin >> input;
    keypad(input);
}