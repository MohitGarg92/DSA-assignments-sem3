#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 2, 2, 8, 4, 6, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                // Shift elements left to overwrite duplicate
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;   // Reduce size
                j--;   // Recheck at same index after shifting
            }
        }
    }

    cout << "Array without duplicates: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
