#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

unsigned long long dp[101];
int last;

unsigned long long solve(int n) {
    if (dp[n] != 0)
        return dp[n];

    for (int i = last + 1; i <= n; i++)
        dp[i] = dp[i - 3] + dp[i - 2];
    last = n;
    return dp[n];
}

int main() {
    FAST_IO

    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    last = 5;

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        cout << solve(N) << '\n';
    }
}
