#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;  // to count distinct elements

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

        // check if arr[i] appeared before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate)
            count++; // count it as a distinct element
    }

    cout << "Total number of distinct elements = " << count << endl;

    return 0;
}
