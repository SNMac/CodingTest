#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> s;
    queue<int> q;
    int queueCnt = 0;
    int dsStat[100000];

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0)
            queueCnt++;
        dsStat[i] = a;
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        if (dsStat[i] == 0)
            s.push(b);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        if (queueCnt == 0) {  // stack only
            cout << c << ' ';
        } else {
            q.push(c);
            if (!s.empty()) {
                cout << s.top() << ' ';
                s.pop();
            } else {
                cout << q.front() << ' ';
                q.pop();
            }
        }
    }
}
