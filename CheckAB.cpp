#include <cstring>
bool flag = true;
bool checkAB(char input[]) {
	// Write your code 
    if(strlen(input) == 0)
        return true;
    if(flag)
    {    
        if(strlen(input) > 1 && input[0] == 'b')
        {    
             flag = false;
            return false;
        }
        else
            flag = false;
    }
    
    if(input[0] == 'a')
        return checkAB(input + 1);
    else if(input[0] == 'b' && input[1] == 'b')
    {    
        if(input[2] == 'b')
            return false;
        checkAB(input + 2);
    }
    else
        return false;

}
