#include <iostream>
using namespace std;
void BubbleSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                //swap
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int linearSearch(int arr[],int n)
{
    for(int i=0;i<n;i++)
    if(arr[i]!=i+1)
    return i+1;
    return n;
}
int BinarySearch(int arr[] , int n)
{
    int start=0;
    int end = n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]!=(mid-1))
        {
            if(mid==0 || arr[mid]!=arr[mid-1])
            return mid+1;
            end=mid-1;
        }
        else
        start=mid+1;
    }
    return n+1;
}
int main()
{
    // find the missing number in the array
    int arr[] = {1,2,3,4,6,7,8,9,10};
    int n= sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,n);
    cout<<linearSearch(arr,n)<<endl;
    cout<<BinarySearch(arr, n)<<endl;
}
