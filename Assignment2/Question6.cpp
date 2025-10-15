#include <iostream>
using namespace std;

// Function to display a triplet matrix
void display(int triplet[][3], int n) {
    cout << "\nRow\tCol\tValue\n";
    for (int i = 0; i < n; i++) {
        cout << triplet[i][0] << "\t" << triplet[i][1] << "\t" << triplet[i][2] << endl;
    }
}

// Function to find transpose of a sparse matrix
void transpose(int A[][3], int At[][3]) {
    At[0][0] = A[0][1]; // rows become cols
    At[0][1] = A[0][0]; // cols become rows
    At[0][2] = A[0][2]; // same number of non-zero elements

    int k = 1;
    for (int col = 0; col < A[0][1]; col++) {
        for (int i = 1; i <= A[0][2]; i++) {
            if (A[i][1] == col) {
                At[k][0] = A[i][1];
                At[k][1] = A[i][0];
                At[k][2] = A[i][2];
                k++;
            }
        }
    }
}

// Function to add two sparse matrices
void add(int A[][3], int B[][3], int C[][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Addition not possible. Matrices dimensions must be same.\n";
        return;
    }

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    int i = 1, j = 1, k = 1;
    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        } else if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        } else {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
    }

    while (i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    while (j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;
}

// Function to multiply two sparse matrices
void multiply(int A[][3], int B[][3], int C[][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Multiplication not possible.\n";
        return;
    }

    int Bt[20][3];
    transpose(B, Bt);

    C[0][0] = A[0][0];
    C[0][1] = B[0][1];
    int k = 1;

    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= Bt[0][2]; j++) {
            if (A[i][1] == Bt[j][1]) {
                int r = A[i][0];
                int c = Bt[j][0];
                int val = A[i][2] * Bt[j][2];

                // check if (r, c) already exists
                int found = 0;
                for (int x = 1; x < k; x++) {
                    if (C[x][0] == r && C[x][1] == c) {
                        C[x][2] += val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    C[k][0] = r;
                    C[k][1] = c;
                    C[k][2] = val;
                    k++;
                }
            }
        }
    }
    C[0][2] = k - 1;
}

int main() {
    int A[20][3], B[20][3], T[20][3], Sum[20][3], Product[20][3];
    int n1, n2;

    cout << "Enter rows, cols and number of non-zero elements for Matrix A: ";
    cin >> A[0][0] >> A[0][1] >> A[0][2];
    cout << "Enter the triplet form (row col value):\n";
    for (int i = 1; i <= A[0][2]; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "\nEnter rows, cols and number of non-zero elements for Matrix B: ";
    cin >> B[0][0] >> B[0][1] >> B[0][2];
    cout << "Enter the triplet form (row col value):\n";
    for (int i = 1; i <= B[0][2]; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    int choice;
    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Transpose of Matrix A\n";
        cout << "2. Addition of A and B\n";
        cout << "3. Multiplication of A and B\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                transpose(A, T);
                cout << "\nTranspose of Matrix A:";
                display(T, T[0][2] + 1);
                break;

            case 2:
                add(A, B, Sum);
                cout << "\nAddition (A + B):";
                display(Sum, Sum[0][2] + 1);
                break;

            case 3:
                multiply(A, B, Product);
                cout << "\nMultiplication (A × B):";
                display(Product, Product[0][2] + 1);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
