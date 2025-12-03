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

Node* searchRec(Node* root, int x){
    if(!root || root->val==x) return root;
    if(x < root->val) return searchRec(root->left,x);
    return searchRec(root->right,x);
}

Node* searchNonRec(Node* root, int x){
    while(root){
        if(root->val==x) return root;
        else if(x < root->val) root=root->left;
        else root=root->right;
    }
    return NULL;
}

Node* minNode(Node* root){
    while(root && root->left) root=root->left;
    return root;
}

Node* maxNode(Node* root){
    while(root && root->right) root=root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* x){
    if(x->right) return minNode(x->right);
    Node* succ=NULL;
    while(root){
        if(x->val < root->val){
            succ=root;
            root=root->left;
        } else if(x->val > root->val){
            root=root->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* x){
    if(x->left) return maxNode(x->left);
    Node* pre=NULL;
    while(root){
        if(x->val > root->val){
            pre=root;
            root=root->right;
        } else if(x->val < root->val){
            root=root->left;
        } else break;
    }
    return pre;
}

int main(){
    Node* root=NULL;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        root=insertBST(root,x);
    }

    int key;
    cin>>key;

    Node* r1 = searchRec(root,key);
    Node* r2 = searchNonRec(root,key);

    if(r1) cout<<"Found Rec\n"; else cout<<"Not Found Rec\n";
    if(r2) cout<<"Found NonRec\n"; else cout<<"Not Found NonRec\n";

    cout<<minNode(root)->val<<"\n";
    cout<<maxNode(root)->val<<"\n";

    if(r1){
        Node* s = inorderSuccessor(root,r1);
        Node* p = inorderPredecessor(root,r1);
        if(s) cout<<s->val<<"\n"; else cout<<"NA\n";
        if(p) cout<<p->val<<"\n"; else cout<<"NA\n";
    }
}
    