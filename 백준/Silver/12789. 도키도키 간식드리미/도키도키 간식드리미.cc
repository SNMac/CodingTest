#include <iostream>
#include <stack>
#include <queue>

#define MAX 1000
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> s;
    queue<int> q;
    int n, input;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        q.push(input);
    }

    int cur = 1;
    while (!q.empty() || !s.empty()) {
        if (q.front() == cur) {
            q.pop();
            cur++;
        } else {  // q.front() > cur
            if (s.empty()) {
                s.push(q.front());
                q.pop();
            } else {  // s.empty == false
                if (s.top() == cur) {
                    s.pop();
                    cur++;
                } else if (s.top() > q.front()) {
                    s.push(q.front());
                    q.pop();
                } else {  // s.top() < q.front()
                    cout << "Sad" << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "Nice" << '\n';
}
