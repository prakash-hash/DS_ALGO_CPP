int staircase(int n){
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    if(n == 1 || n == 0)
        return 1;
    else if(n == 2)
        return 2;
    else if(n ==3)
        return 4;
    int x = staircase(n-1);
    int y = staircase(n-2);
    int z = staircase(n-3);
    
    return x+y+z;
    
}
