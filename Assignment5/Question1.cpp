#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBeg(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->next = head;
    head = temp;
}

void insertAtEnd(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->next = nullptr;
    if (!head) {
        head = temp;
        return;
    }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = temp;
}

void insertBefore(int key, int val) {
    if (!head) return;
    if (head->data == key) {
        insertAtBeg(val);
        return;
    }
    Node* p = head;
    while (p->next && p->next->data != key) p = p->next;
    if (p->next) {
        Node* temp = new Node;
        temp->data = val;
        temp->next = p->next;
        p->next = temp;
    }
}

void insertAfter(int key, int val) {
    Node* p = head;
    while (p && p->data != key) p = p->next;
    if (p) {
        Node* temp = new Node;
        temp->data = val;
        temp->next = p->next;
        p->next = temp;
    }
}

void deleteBeg() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* p = head;
    while (p->next->next) p = p->next;
    delete p->next;
    p->next = nullptr;
}

void deleteKey(int key) {
    if (!head) return;
    if (head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        return;
    }
    Node* p = head;
    while (p->next && p->next->data != key) p = p->next;
    if (p->next) {
        Node* t = p->next;
        p->next = t->next;
        delete t;
    }
}

int searchNode(int key) {
    Node* p = head;
    int pos = 1;
    while (p) {
        if (p->data == key) return pos;
        pos++;
        p = p->next;
    }
    return -1;
}

void displayList() {
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

void findMiddle() {
    if (!head) return;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
}

void reverseList() {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
}

int main() {
    int ch, val, key;
    while (true) {
        cout << "\n1.Insert Beg\n2.Insert End\n3.Insert Before\n4.Insert After\n5.Delete Beg\n6.Delete End\n7.Delete Key\n8.Search\n9.Display\n10.Count & Delete\n11.Middle\n12.Reverse\n13.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> val; insertAtBeg(val); break;
            case 2: cin >> val; insertAtEnd(val); break;
            case 3: cin >> key >> val; insertBefore(key, val); break;
            case 4: cin >> key >> val; insertAfter(key, val); break;
            case 5: deleteBeg(); break;
            case 6: deleteEnd(); break;
            case 7: cin >> key; deleteKey(key); break;
            case 8: cin >> key; cout << searchNode(key) << endl; break;
            case 9: displayList(); break;
            case 10: cin >> key; cout << countAndDelete(key) << endl; displayList(); break;
            case 11: findMiddle(); break;
            case 12: reverseList(); displayList(); break;
            case 13: return 0;
        }
    }
}
