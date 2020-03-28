#include <iostream>
#include <cmath>

using namespace std;

void print_sub(string input,string output)
{
	if(input.empty())
	{	
		cout << output << endl;
		return;
	}
	string smallinput = input.substr(1);
	print_sub(smallinput,output);
	print_sub(smallinput,output + input[0]);

}

int main()
{
	string input;
	cin>>input;
	string output = "";
	print_sub(input,output);
}
