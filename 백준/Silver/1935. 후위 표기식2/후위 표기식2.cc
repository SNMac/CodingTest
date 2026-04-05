#include <iostream>
#include <string>
#include <stack>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int N;
string input;
int num[26];
stack<double> operad;

int main() {
    FAST_IO

    cin >> N;
    cin.ignore();
    getline(cin, input);
    for (int i = 0; i < N; i++)
        cin >> num[i];

    for (auto c : input) {
        if (isalpha(c)) {
            operad.push(num[c - 65]);
        } else {
            double b = operad.top(); operad.pop();
            double a = operad.top(); operad.pop();

            switch (c) {
                case '+' :
                    operad.push(a + b);
                    break;

                case '-' :
                    operad.push(a - b);
                    break;

                case '*' :
                    operad.push(a * b);
                    break;

                case '/' :
                    operad.push(a / b);
                    break;
            }
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << operad.top() << '\n';
}
