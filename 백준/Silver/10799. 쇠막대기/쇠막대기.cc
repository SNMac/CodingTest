#include <iostream>
#include <string>
#include <stack>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int main() {
    FAST_IO

    string input;
    cin >> input;
    stack<char> s;
    int total = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            if (input[i + 1] == ')') {  // 레이저
                total += s.size();
                i++;
            } else {  // input[i + 1] == '(', 쇠막대기 시작
                s.push(input[i]);
            }
        } else {  // input[i] == ')', 쇠막대기 끝
            s.pop();
            total++;
        }
    }
    cout << total << '\n';
}
