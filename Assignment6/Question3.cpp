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

int size_doubly(Node* start) {
    int c = 0;
    Node *t = start;
    while(t) {
        c++;
        t = t->next;
    }
    return c;
}

int size_circular(Node* head) {
    if(!head) return 0;
    int c = 0;
    Node *t = head;
    do {
        c++;
        t = t->next;
    } while(t != head);
    return c;
}

int main() {
    Node *a = makeNode(10);
    Node *b = makeNode(20);
    Node *c = makeNode(30);

    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;

    cout << "Size of Doubly Linked List: " << size_doubly(a) << endl;

    Node *x = makeNode(1);
    Node *y = makeNode(2);
    Node *z = makeNode(3);

    x->next = y;
    y->next = z;
    z->next = x;

    cout << "Size of Circular Linked List: " << size_circular(x) << endl;
}
