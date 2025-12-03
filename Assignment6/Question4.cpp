#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *next;
    Node *prev;
};

Node* makeNode(char x) {
    Node *p = new Node;
    p->data = x;
    p->next = 0;
    p->prev = 0;
    return p;
}

int is_palindrome(Node* start) {
    if(!start) return 1;

    Node *l = start;
    Node *r = start;

    while(r->next) r = r->next;

    while(l != r && r->next != l) {
        if(l->data != r->data) return 0;
        l = l->next;
        r = r->prev;
    }
    return 1;
}

int main() {
    Node *a = makeNode('r');
    Node *b = makeNode('a');
    Node *c = makeNode('d');
    Node *d = makeNode('a');
    Node *e = makeNode('r');

    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    c->next = d;
    d->prev = c;
    d->next = e;
    e->prev = d;

    cout << (is_palindrome(a) ? "True" : "False");
}
