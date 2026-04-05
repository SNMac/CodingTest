#include <iostream>
#include <stack>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int A[1000001];
int F[1000001];
int NGF[1000001];
stack<int> s;

int main() {
    FAST_IO

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        F[A[i]]++;
    }

    for (int i = N; i >= 1; i--) {
        while (!s.empty() && F[s.top()] <= F[A[i]])
            s.pop();

        if (s.empty()) {
            NGF[i] = -1;
        } else {
            NGF[i] = s.top();
        }
        s.push(A[i]);
    }

    for (int i = 1; i <= N; i++)
        cout << NGF[i] << ' ';
    cout << '\n';
}
