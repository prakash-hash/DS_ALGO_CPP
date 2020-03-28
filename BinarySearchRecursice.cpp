int RbinarySearch(int input[],int low,int high,int key)
{
    if(low == high)
    {
        if(input[low] == key)
            return low;
        else
            return -1;
    }
    else
    {
        int mid = (low+high)/2;
        if(input[mid] == key)
            return mid;
        if(input[mid] > key)
            return RbinarySearch(input,low,mid-1,key);
        else
            return RbinarySearch(input,mid+1,high,key);
    }
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
    return RbinarySearch(input,0,size-1,element);
    
}
