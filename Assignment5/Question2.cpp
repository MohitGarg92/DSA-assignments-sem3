#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertEnd(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->next = nullptr;
    if (!head) head = temp;
    else {
        Node* p = head;
        while (p->next) p = p->next;
        p->next = temp;
    }
}

void display() {
    Node* p = head;
    while (p) {
        cout << p->data;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;
}

int countAndDelete(int key) {
    int cnt = 0;
    while (head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        cnt++;
    }
    Node* p = head;
    while (p && p->next) {
        if (p->next->data == key) {
            Node* t = p->next;
            p->next = t->next;
            delete t;
            cnt++;
        } else p = p->next;
    }
    return cnt;
}

int main() {
    int n, val, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertEnd(val);
    }
    cin >> key;
    int cnt = countAndDelete(key);
    cout << "Count: " << cnt << endl;
    cout << "Updated Linked List: ";
    display();
}
