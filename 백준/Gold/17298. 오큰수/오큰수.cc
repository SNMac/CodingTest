#include <iostream>
#include <stack>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int A[1000001];
int NGE[1000001];
stack<int> s;

int main() {
    FAST_IO

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = N; i >= 1; i--) {
        while (!s.empty() && s.top() <= A[i])
            s.pop();

        if (s.empty()) {
            NGE[i] = -1;
        } else {
            NGE[i] = s.top();
        }
        s.push(A[i]);
    }

    for (int i = 1; i <= N; i++)
        cout << NGE[i] << ' ';
}
