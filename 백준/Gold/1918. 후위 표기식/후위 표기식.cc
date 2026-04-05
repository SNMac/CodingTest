#include <iostream>
#include <string>
#include <stack>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

string input;
string output;
stack<pair<char, int>> opertr;

int main() {
    FAST_IO

    getline(cin, input);

    for (int i = 0; i < input.length(); i++) {
        if (isalpha(input[i])) {
            output += input[i];
        } else if (input[i] == '*' || input[i] == '/') {
            if (!opertr.empty() && opertr.top().second == 0) {
                while(!opertr.empty() && opertr.top().second == 0) {
                    output += opertr.top().first;
                    opertr.pop();
                }
            }
            opertr.emplace(input[i], 0);
        } else if (input[i] == '+' || input[i] == '-') {
            if (!opertr.empty() && opertr.top().second >= 0) {
                while(!opertr.empty() && opertr.top().second >= 0) {
                    output += opertr.top().first;
                    opertr.pop();
                }
            }
            opertr.emplace(input[i], 1);
        } else if (input[i] == '(') {
          opertr.emplace(input[i], -1);
        } else if (input[i] == ')') {
            while (opertr.top().first != '(') {
                output += opertr.top().first;
                opertr.pop();
            }
            opertr.pop();
        }
    }
    while (!opertr.empty()) {
        output += opertr.top().first;
        opertr.pop();
    }

    cout << output << '\n';
}
