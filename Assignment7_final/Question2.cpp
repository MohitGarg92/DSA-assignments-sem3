#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n){
    int left=0, right=n-1;
    while(left<right){
        int minIndex=left, maxIndex=right;
        if(a[minIndex]>a[maxIndex]){
            int t=a[minIndex];
            a[minIndex]=a[maxIndex];
            a[maxIndex]=t;
        }
        for(int i=left+1;i<right;i++){
            if(a[i]<a[minIndex]) minIndex=i;
            if(a[i]>a[maxIndex]) maxIndex=i;
        }
        int t=a[left]; a[left]=a[minIndex]; a[minIndex]=t;
        if(maxIndex==left) maxIndex=minIndex;
        t=a[right]; a[right]=a[maxIndex]; a[maxIndex]=t;
        left++;
        right--;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    improvedSelectionSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
