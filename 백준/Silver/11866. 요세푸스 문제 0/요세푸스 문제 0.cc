#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<int> q;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        q.push(i);

    cout << '<';
    while(true) {
        for (int i = 1; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if (q.empty()) {
            cout << '>';
            return 0;
        } else
            cout << ", ";
    }
}