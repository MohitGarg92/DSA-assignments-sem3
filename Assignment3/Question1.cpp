#include <iostream>
using namespace std;

class Stack {
    int top, size;
    int *arr;
public:
    Stack(int n) {
        size = n;
        arr = new int[size];
        top = -1;
    }
    void push(int val) {
        if (top == size - 1) {
            cout << "Stack is full\n";
            return;
        }
        arr[++top] = val;
        cout << "Pushed " << val << endl;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }
    void peek() {
        if (top == -1) cout << "Stack is empty\n";
        else cout << "Top element: " << arr[top] << endl;
    }
    void display() {
        if (top == -1) cout << "Stack is empty\n";
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) cout << arr[i] << " ";
            cout << endl;
        }
    }
    void isEmpty() {
        cout << (top == -1 ? "Yes\n" : "No\n");
    }
    void isFull() {
        cout << (top == size - 1 ? "Yes\n" : "No\n");
    }
};

int main() {
    int n, ch, val;
    cout << "Enter stack size: ";
    cin >> n;
    Stack s(n);
    while (true) {
        cout << "\n1.Push 2.Pop 3.Peek 4.Display 5.isEmpty 6.isFull 7.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; s.push(val); break;
            case 2: s.pop(); break;
            case 3: s.peek(); break;
            case 4: s.display(); break;
            case 5: s.isEmpty(); break;
            case 6: s.isFull(); break;
            case 7: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
