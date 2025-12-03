#include <iostream>
using namespace std;

void mergeArr(int a[], int l, int m, int r){
    int n1=m-l+1, n2=r-m;
    int x[n1], y[n2];
    for(int i=0;i<n1;i++) x[i]=a[l+i];
    for(int i=0;i<n2;i++) y[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(x[i]<=y[j]) a[k++]=x[i++];
        else a[k++]=y[j++];
    }
    while(i<n1) a[k++]=x[i++];
    while(j<n2) a[k++]=y[j++];
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        mergeArr(a,l,m,r);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
