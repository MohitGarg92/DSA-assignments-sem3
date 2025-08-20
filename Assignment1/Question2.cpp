#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ) {
            if (arr[i] == arr[j]) 
            {
                for (int k = j; k < length - 1; ++k) {
                    arr[k] = arr[k + 1];
                }
                length--;
            } 
            else 
            {
                j++;
            }
        }
    }
    return length;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int length = sizeof(arr)/sizeof(arr[0]);

    length = removeDuplicates(arr, length);

    cout << "final Array ";
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
