#include <iostream>
using namespace std;

// Node structure for a Circular Singly Linked List (CSLL)
// Note: We removed the unused 'prev' pointer for consistency.
struct Node {
    int data;
    Node *next;
};

// Function to create a new node
Node* makeNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = 0; // Initialize next to NULL
    return p;
}

// Function to insert a node at the beginning (new head)
void insert_first(Node* &head, int x) {
    Node *p = makeNode(x);
    if(!head) {
        head = p;
        p->next = p; // If list is empty, new head points to itself
    } else {
        Node *t = head;
        // Find the tail (the node whose next points back to head)
        while(t->next != head) t = t->next;
        
        p->next = head; // New node points to old head
        t->next = p; // Tail points to new node
        head = p; // Update head
    }
}

// Function to insert a node at the end (new tail)
void insert_last(Node* &head, int x) {
    Node *p = makeNode(x);
    if(!head) {
        head = p;
        p->next = p;
    } else {
        Node *t = head;
        // Find the tail
        while(t->next != head) t = t->next;
        
        t->next = p; // Tail points to new node
        p->next = head; // New node points to head
    }
}

// Function to delete a node with a specific value 'x'
void delete_node(Node* &head, int x) {
    if(!head) return;
    
    Node *t = head, *p = 0; // t is current, p is previous

    // Search for the node to delete
    do {
        if(t->data == x) break;
        p = t;
        t = t->next;
    } while(t != head);

    // If the element was not found
    if(t->data != x) return; 

    // CASE 1: Only one node in the list
    if(t == head && t->next == head) {
        head = 0;
    } 
    // CASE 2: Deleting the head node in a list with >1 node
    else if(t == head) {
        // Find the tail node (which is p if we exit the loop)
        while(p->next != head) p = p->next; 
        
        head = head->next; // Move head to the next node
        p->next = head; // Tail now points to the new head
    } 
    // CASE 3: Deleting a node in the middle or the tail
    else { 
        p->next = t->next; // Previous node skips the current node
    }

    delete t; // Free the memory
}

// Function to search for a value 'x'
int search_node(Node* head, int x) {
    if(!head) return 0;
    Node *t = head;
    do {
        if(t->data == x) return 1;
        t = t->next;
    } while(t != head); // Continue until we loop back to head
    return 0;
}

// Function to display the list contents
void show(Node* head) {
    if(!head) {
        cout << "List is empty." << endl;
        return;
    }
    Node *t = head;
    do {
        cout << t->data << " -> ";
        t = t->next;
    } while(t != head);
    cout << "(Head " << head->data << ") (Circular)" << endl;
}

// The necessary main function to test the list
int main() {
    Node* my_list = 0; // Start with an empty list

    cout << "--- Circular Singly Linked List Operations ---" << endl;
    
    // 1. Test Insertions
    insert_last(my_list, 10);
    insert_last(my_list, 30);
    insert_first(my_list, 5);
    insert_first(my_list, 1);
    
    cout << "\nAfter insertions (1, 5, 10, 30):" << endl;
    show(my_list); // Expected: 1 -> 5 -> 10 -> 30 -> (Circular)
    

    // 2. Test Search
    cout << "\nSearching for 10: " << (search_node(my_list, 10) ? "Found" : "Not Found") << endl;
    cout << "Searching for 100: " << (search_node(my_list, 100) ? "Found" : "Not Found") << endl;

    // 3. Test Deletion
    cout << "\nTesting Deletion..." << endl;
    
    // Delete Head (1)
    delete_node(my_list, 1); 
    cout << "Delete 1 (Head):" << endl;
    show(my_list); // Expected: 5 -> 10 -> 30 -> (Circular)
    
    // Delete Middle (10)
    delete_node(my_list, 10); 
    cout << "Delete 10 (Middle):" << endl;
    show(my_list); // Expected: 5 -> 30 -> (Circular)
    
    // Delete Tail (30)
    delete_node(my_list, 30); 
    cout << "Delete 30 (Tail):" << endl;
    show(my_list); // Expected: 5 -> (Circular)
    
    // Delete the only node (5)
    delete_node(my_list, 5);
    cout << "Delete 5 (Last Node):" << endl;
    show(my_list); // Expected: List is empty.

    return 0;
}