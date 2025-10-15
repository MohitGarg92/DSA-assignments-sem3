#include <iostream>
#include <stack>
using namespace std;

int main() {
    string text;
    cout << "Enter string: ";
    cin >> text;
    stack<char> s;
    for (char c : text) 
      {
        s.push(c);
      }
    string rev = "";
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }
    cout << "Reversed: " << rev;
}
