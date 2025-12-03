#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v){ val=v; left=right=NULL; }
};

Node* insertBST(Node* root, int x){
    if(!root) return new Node(x);
    if(x < root->val) root->left = insertBST(root->left,x);
    else if(x > root->val) root->right = insertBST(root->right,x);
    return root;
}

Node* minNode(Node* root){
    while(root->left) root=root->left;
    return root;
}

Node* deleteBST(Node* root, int x){
    if(!root) return root;
    if(x < root->val) root->left = deleteBST(root->left,x);
    else if(x > root->val) root->right = deleteBST(root->right,x);
    else{
        if(!root->left){
            Node* r=root->right;
            delete root;
            return r;
        }
        if(!root->right){
            Node* l=root->left;
            delete root;
            return l;
        }
        Node* t=minNode(root->right);
        root->val=t->val;
        root->right=deleteBST(root->right,t->val);
    }
    return root;
}

int maxDepth(Node* root){
    if(!root) return 0;
    int l=maxDepth(root->left);
    int r=maxDepth(root->right);
    return max(l,r)+1;
}

int minDepth(Node* root){
    if(!root) return 0;
    if(!root->left) return minDepth(root->right)+1;
    if(!root->right) return minDepth(root->left)+1;
    int l=minDepth(root->left);
    int r=minDepth(root->right);
    return min(l,r)+1;
}

int main(){
    Node* root=NULL;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        root = insertBST(root,x);
    }

    int del;
    cin>>del;
    root = deleteBST(root,del);

    cout<<maxDepth(root)<<"\n";
    cout<<minDepth(root)<<"\n";
}
