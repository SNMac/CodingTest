#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int N, S;
int A[100000];
int D;

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main() {
    FAST_IO

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A[i] = abs(S - temp);
    }

    D = A[0];
    for (int i = 1; i < N; i++)
        D = gcd(D, A[i]);

    cout << D << '\n';
}
