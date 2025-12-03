#include <iostream>
using namespace std;

class PriorityQueue{
    int h[1000];
    int size;

    void heapify(int i){
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<size && h[l] > h[largest]) largest=l;
        if(r<size && h[r] > h[largest]) largest=r;
        if(largest!=i){
            int t=h[i];
            h[i]=h[largest];
            h[largest]=t;
            heapify(largest);
        }
    }

public:
    PriorityQueue(){
        size=0;
    }

    void push(int x){
        h[size]=x;
        int i=size;
        size++;
        while(i>0 && h[i] > h[(i-1)/2]){
            int t=h[i];
            h[i]=h[(i-1)/2];
            h[(i-1)/2]=t;
            i=(i-1)/2;
        }
    }

    int top(){
        if(size==0) return -1;
        return h[0];
    }

    void pop(){
        if(size==0) return;
        h[0]=h[size-1];
        size--;
        heapify(0);
    }

    bool empty(){
        return size==0;
    }
};

int main(){
    PriorityQueue pq;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
