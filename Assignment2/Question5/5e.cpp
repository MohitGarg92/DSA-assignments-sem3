#include<iostream>
using namespace std;
class Symmetric {
    int *A;
    int n;
public:
    Symmetric(int n) {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }

    void set(int i, int j, int x) {
        if (i >= j)
            A[i * (i - 1) / 2 + (j - 1)] = x;
    }

    int get(int i, int j) {
        if (i >= j)
            return A[i * (i - 1) / 2 + (j - 1)];
        else
            return A[j * (j - 1) / 2 + (i - 1)];
    }

    void display() {
        cout << "Symmetric Matrix:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};
