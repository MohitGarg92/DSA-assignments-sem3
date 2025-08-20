#include <iostream>
using namespace std;

class Question1 {
    int length;
    int* array;

public:
    Question1
() {
        array = nullptr;
        length = 0;
    }

    void CreateArray() {
        cout << "please enter the length of array" << endl;
        cin >> length;
        array = new int[length + 1];
        cout << "please enter the array elements" << endl;
        for (int i = 0; i < length; i++) {
            cin >> array[i];
        }
    }

    void PrintElements() {
        for (int i = 0; i < length; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void InsertElement() {
        cout << "please enter the position of number where it is to be inserted " << endl;
        int pos, num;
        cin >> pos;
        cout << "enter the number to be inserted" << endl;
        cin >> num;

        for (int i = length; i >= pos; i--) {
            array[i] = array[i - 1];
        }
        array[pos - 1] = num;
        length++;
        PrintElements();
    }

    void deleteElement() {
        cout << "enter the position of the element that is to be deleted" << endl;
        int del;
        cin >> del;

        if (del < length) {
            for (int i = del - 1; i < length - 1; i++) {
                array[i] = array[i + 1];
            }
            length--;
        }
        PrintElements();
    }

    int LinearSearch() {
        cout << "enter the number to be searched" << endl;
        int target;
        cin >> target;

        for (int i = 0; i < length; i++) {
            if (array[i] == target)
                return i + 1;
        }
        return -1;
    }

    ~Question1
() {
        delete[] array;
    }
};

int main() {
    Question1
 q;
    q.CreateArray();
    q.PrintElements();
    q.InsertElement();
    q.deleteElement();
    int index = q.LinearSearch();

    if (index > 0)
        cout << "array found at index " << index << endl;
    else
        cout << "element not found" << endl;

    cout << "thank you" << endl;
    return 0;
}
