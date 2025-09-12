#include<iostream>
using namespace std;
int BinarySearch(int arr[],int n,int target)
{
    int start=0;
    int end = n-1;
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(arr[mid]==target)
        return mid;
        else if(arr[mid]>target)
        end=mid-1;
        else 
        start=mid+1;
    }
    return -1;
}
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
int main()
{
    int arr[] = {64,34,25,12,22,11,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,n);
    int target = 64;
    int ans=BinarySearch(arr,n,target);
    (ans!=-1)?cout<<ans:cout<<"not found";
}
