#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);  // convert to lowercase for easy comparison
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    string str, result = "";
    cout << "Enter a string: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (!isVowel(str[i])) {
            result += str[i];  // keep only non-vowels
        }
    }

    cout << "String after deleting vowels: " << result << endl;
    return 0;
}
