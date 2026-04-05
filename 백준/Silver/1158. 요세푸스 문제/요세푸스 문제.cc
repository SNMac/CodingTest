#include <iostream>
#include <queue>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int main() {
    FAST_IO

    queue<int> q;
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        q.push(i);
    cout << '<';
    while (q.size() != 1) {
        for (int j = 1; j < K; j++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">\n";
}
