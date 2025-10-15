#include <iostream>
#include <stack>
using namespace std;

int evaluate(string exp) {
    stack<int> s;
    for (char c : exp) {
        if (isdigit(c)) s.push(c - '0');
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int res;
            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') res = a / b;
            else if (c == '^') {
                res = 1;
                for (int i = 0; i < b; i++) res *= a;
            }
            s.push(res);
        }
    }
    return s.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;
    cout << "Result: " << evaluate(exp);
}
