#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int sub_sequence(string input, string output[])
{
	if(input.empty())
	{	
		output[0] = "";
		return 1;
	}
	string small_input = input.substr(1);
	int smallOutputSize = sub_sequence(small_input,output);
	for(int i = 0; i < smallOutputSize; i++)
		output[i + smallOutputSize] = input[0] + output[i];
	return 2*smallOutputSize;
}

int main()
{
	string input;
	cin>>input;
	int len = pow(2,input.size());
	string* output = new string[len];
	int count = sub_sequence(input,output);
	for(int i = 0; i < count; i++)
		cout<<output[i]<<endl;

}
