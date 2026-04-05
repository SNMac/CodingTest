#include <iostream>
#include <queue>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int main() {
    FAST_IO

    queue<int> q1;
    queue<int> q2;
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        q1.push(i);
    while (!q1.empty()) {
        for (int j = 1; j < K; j++) {
            q1.push(q1.front());
            q1.pop();
        }
        q2.push(q1.front());
        q1.pop();
    }
    cout << '<' << q2.front();
    while (true) {
        q2.pop();
        if (q2.empty())
            break;
        cout << ", " << q2.front();
    }
    cout << ">\n";
}
