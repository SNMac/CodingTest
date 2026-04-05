#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    while(true) {
        stack<char> s;
        getline(cin, str);
        bool exit = false;
        if (str == ".")
            break;
        for (char c : str) {
            if (exit)
                break;
            switch (c) {
                case '(' :
                    s.push(c);
                    break;
                case ')' :
                    if (!s.empty() && s.top() == '(')
                        s.pop();
                    else
                        exit = true;
                    break;
                case '[' :
                    s.push(c);
                    break;
                case ']' :
                    if (!s.empty() && s.top() == '[')
                        s.pop();
                    else
                        exit = true;
                    break;
            }
        }
        if (exit | !s.empty())
            cout << "no\n";
        else
            cout << "yes\n";
    }
}