#include<iostream>
using namespace std;

class Array {
    int length;
    int arr[100];

public:
    Array(int length) {
        this->length = length;
        for (int i = 0; i < length; i++) {
            arr[i] = i + 1;
        }
    }

    void Reverse() {
        for (int i = 0; i < length / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[length - i - 1];
            arr[length - i - 1] = temp;
        }
    }

    void display() {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Matrix {
    int rows;
    int cols;
    int mat[100][100];

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = i + j + 1;
            }
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void multiply(Matrix& other, Matrix& result) {
        if (cols != other.rows) {
            cout << "Matrix dimensions incompatible for multiplication" << endl;
            return;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
    }

    void transpose(Matrix& result) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[j][i] = mat[i][j];
            }
        }
        result.rows = cols;
        result.cols = rows;
    }
};

int main() {
    Array arr(5);
    cout << "Original Array: ";
    arr.display();
    arr.Reverse();
    cout << "Reversed Array: ";
    arr.display();

    Matrix A(2, 3);
    Matrix B(3, 2);
    Matrix C(2, 2);
    Matrix T(3, 2); // Transposed matrix

    cout << "\nMatrix A:" << endl;
    A.display();

    cout << "\nMatrix B:" << endl;
    B.display();

    A.multiply(B, C);
    cout << "\nMatrix A × B:" << endl;
    C.display();

    B.transpose(T);
    cout << "\nTranspose of Matrix B:" << endl;
    T.display();

    return 0;
}
