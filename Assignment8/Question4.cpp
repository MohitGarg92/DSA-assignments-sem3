#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v){ val=v; left=right=NULL; }
};

Node* build(Node* root, int x){
    if(!root) return new Node(x);
    if(x < root->val) root->left = build(root->left,x);
    else root->right = build(root->right,x);
    return root;
}

bool isBSTUtil(Node* root, long long mn, long long mx){
    if(!root) return true;
    if(root->val <= mn || root->val >= mx) return false;
    return isBSTUtil(root->left,mn,root->val) &&
           isBSTUtil(root->right,root->val,mx);
}

bool isBST(Node* root){
    return isBSTUtil(root,-1e18,1e18);
}

int main(){
    Node* root=NULL;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        root = build(root,x);
    }
    if(isBST(root)) cout<<"YES";
    else cout<<"NO";
}
