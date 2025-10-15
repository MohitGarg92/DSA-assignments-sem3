#include <iostream>
using namespace std;

class Queue {
    int *arr, front, rear, size;
public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int x) {
        if (isFull()) cout << "Queue is full\n";
        else {
            if (front == -1) front = 0;
            arr[++rear] = x;
        }
    }

    void dequeue() {
        if (isEmpty()) cout << "Queue is empty\n";
        else {
            cout << "Deleted: " << arr[front++] << endl;
        }
    }

    void display() {
        if (isEmpty()) cout << "Queue is empty\n";
        else {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }

    void peek() {
        if (isEmpty()) cout << "Queue is empty\n";
        else cout << "Front: " << arr[front] << endl;
    }
};

int main() {
    int n;
    cout << "Enter size of queue: ";
    cin >> n;
    Queue q(n);
    int ch, val;

    while (1) {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\n";
        cin >> ch;
        if (ch == 1) {
            cin >> val;
            q.enqueue(val);
        } else if (ch == 2) q.dequeue();
        else if (ch == 3) q.display();
        else if (ch == 4) q.peek();
        else if (ch == 5) break;
        else cout << "Invalid\n";
    }
    return 0;
}
