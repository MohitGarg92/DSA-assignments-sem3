#include <iostream>
using namespace std;

class TriDiagonal {
    int *A;
    int n;
public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3 * n - 2];
    }

    void set(int i, int j, int x) {
        if (i - j == 1)
            A[i - 2] = x;          // Lower diagonal
        else if (i == j)
            A[n - 1 + i - 1] = x;  // Main diagonal
        else if (i - j == -1)
            A[2 * n - 1 + i - 1] = x;  // Upper diagonal
    }

    int get(int i, int j) {
        if (i - j == 1)
            return A[i - 2];
        else if (i == j)
            return A[n - 1 + i - 1];
        else if (i - j == -1)
            return A[2 * n - 1 + i - 1];
        else
            return 0;
    }

    void display() {
        cout << "Tri-Diagonal Matrix:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter dimension of Tri-diagonal Matrix: ";
    cin >> n;
    TriDiagonal T(n);

    cout << "Enter elements:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            T.set(i, j, x);
        }
    }

    T.display();
    return 0;
}
