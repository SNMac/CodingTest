#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int p = 0; p < n; p++) {
            int priority;
            cin >> priority;
            q.push({p, priority});
            pq.push(priority);
        }

        int order = 1;
        while(true) {
            if (q.front().second < pq.top()) {
                q.push(q.front());
                q.pop();
            } else {  // q.front() priority > pq.top() priority
                if (q.front().first == m) {
                    cout << order << '\n';
                    break;
                } else {
                    q.pop();
                    pq.pop();
                    order++;
                }
            }
        }
    }
}