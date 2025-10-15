#include <iostream>
#include <stack>
using namespace std;

bool balanced(string exp) {
    stack<char> s;
    for (char c : exp) {
        if (c == '(' || c == '{' || c == '[') s.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false;
            char t = s.top(); s.pop();
            if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '['))
                return false;
        }
    }
    return s.empty();
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;
    cout << (balanced(exp) ? "Balanced" : "Not Balanced");
}
