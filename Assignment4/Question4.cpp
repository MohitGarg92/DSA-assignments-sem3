#include <iostream>
#include <queue>
using namespace std;

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;

    queue<char> q;
    int freq[256] = {0};

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        freq[(int)ch]++;

        q.push(ch);

        if (freq[(int)ch] == 1)
            cout << ch << " ";
        else {
            while (!q.empty() && freq[(int)q.front()] > 1)
                q.pop();
            if (!q.empty())
                cout << q.front() << " ";
            else
                cout << "-1 ";
        }
    }
    return 0;
}
