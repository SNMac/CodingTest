#include <iostream>
#include <stack>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int N;
stack<int> s;

int main() {
    FAST_IO

    cin >> N;

    if (N == 0) {
        s.push(0);
    } else {
        while (N) {
            if (N % -2) {  // odd
                s.push(1);
                N--;
                N /= -2;
            } else {  // even
                s.push(0);
                N /= -2;
            }
        }
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << '\n';
}
