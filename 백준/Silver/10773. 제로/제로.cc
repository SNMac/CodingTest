#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<int> s;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        if (n == 0)
            s.pop();
        else
            s.push(n);
    }

    int total = 0;
    while(!s.empty()) {
        total += s.top();
        s.pop();
    }
    cout << total << '\n';
}