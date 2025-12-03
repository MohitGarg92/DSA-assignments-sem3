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

int is_circular(Node* head) {
    if(!head) return 0;
    Node *t = head->next;
    while(t && t != head) t = t->next;
    return t == head;
}

int main() {
    Node *a = makeNode(10);
    Node *b = makeNode(20);
    Node *c = makeNode(30);

    a->next = b;
    b->next = c;
    c->next = a;

    cout << (is_circular(a) ? "Circular" : "Not Circular");
}
