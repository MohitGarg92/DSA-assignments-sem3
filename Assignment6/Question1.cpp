#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node* makeNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = 0;
    p->prev = 0;
    return p;
}

void insert_first(Node* &start, int x) {
    Node *p = makeNode(x);
    if(!start) start = p;
    else {
        p->next = start;
        start->prev = p;
        start = p;
    }
}

void insert_last(Node* &start, int x) {
    Node *p = makeNode(x);
    if(!start) start = p;
    else {
        Node *t = start;
        while(t->next) t = t->next;
        t->next = p;
        p->prev = t;
    }
}

void insert_after(Node* &start, int k, int x) {
    Node *t = start;
    while(t && t->data != k) t = t->next;
    if(t) {
        Node *p = makeNode(x);
        p->next = t->next;
        p->prev = t;
        if(t->next) t->next->prev = p;
        t->next = p;
    }
}

void insert_before(Node* &start, int k, int x) {
    if(start && start->data == k) {
        insert_first(start, x);
        return;
    }
    Node *t = start;
    while(t && t->next && t->next->data != k) t = t->next;
    if(t && t->next) {
        Node *p = makeNode(x);
        p->next = t->next;
        p->prev = t;
        t->next->prev = p;
        t->next = p;
    }
}

void delete_node(Node* &start, int x) {
    Node *t = start;
    while(t && t->data != x) t = t->next;
    if(!t) return;
    if(t->prev) t->prev->next = t->next;
    else start = t->next;
    if(t->next) t->next->prev = t->prev;
    delete t;
}

int search_node(Node* start, int x) {
    Node *t = start;
    while(t) {
        if(t->data == x) return 1;
        t = t->next;
    }
    return 0;
}

void show(Node* start) {
    Node *t = start;
    while(t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    Node *start = 0;
    int ch, a, b;

    while(true) {
        cout << "\n1 Insert First\n2 Insert Last\n3 Insert After\n4 Insert Before\n5 Delete\n6 Search\n7 Show\n8 Exit\n";
        cin >> ch;
        if(ch==1){ cin>>a; insert_first(start,a); }
        else if(ch==2){ cin>>a; insert_last(start,a); }
        else if(ch==3){ cin>>a>>b; insert_after(start,a,b); }
        else if(ch==4){ cin>>a>>b; insert_before(start,a,b); }
        else if(ch==5){ cin>>a; delete_node(start,a); }
        else if(ch==6){ cin>>a; cout<<(search_node(start,a)?"Found\n":"Not Found\n"); }
        else if(ch==7){ show(start); }
        else if(ch==8) break;
    }
}
