#include <iostream>

using namespace std;

int dp[1001][1001];

int pascalMod(int n, int k) {
    if (dp[n][k] != 0)
        return dp[n][k];

    dp[n][k] = (pascalMod(n - 1, k - 1) % 10007
            + pascalMod(n - 1, k) % 10007) % 10007;
    return dp[n][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 1001; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1;
        dp[i][i] = 1;
    }
    int n, k;
    cin >> n >> k;

    cout << pascalMod(n, k) << '\n';
}