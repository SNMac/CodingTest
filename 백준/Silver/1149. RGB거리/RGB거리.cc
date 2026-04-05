#include <iostream>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int rgb[1001][3];  // [i][0] : r, [i][1] : g, [i][2] : b
int dp[1001][3];
int N;

void solve(int n) {
    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
    }
}

int main() {
    FAST_IO

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];

    solve(N);
    cout << min({dp[N][0], dp[N][1], dp[N][2]}) << '\n';
}
