#include <iostream>
using namespace std;

class Diagonal {
    int *A;
    int n;
public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
    }

    void set(int i, int j, int x) {
        if (i == j) A[i - 1] = x;
    }

    int get(int i, int j) {
        if (i == j) return A[i - 1];
        else return 0;
    }

    void display() {
        cout << "Diagonal Matrix:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    ~Diagonal() {
        delete[] A;
    }
};

int main() {
    int n;
    cout << "Enter dimension of Diagonal Matrix: ";
    cin >> n;

    Diagonal D(n);
    cout << "Enter " << n << " diagonal elements:\n";
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        D.set(i, i, x);
    }

    D.display();
    return 0;
}
