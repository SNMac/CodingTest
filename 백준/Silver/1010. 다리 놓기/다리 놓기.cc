#include <iostream>

using namespace std;

int dp[31][31];

int pascal(int n, int k) {
    if (dp[n][k] != 0)
        return dp[n][k];

    dp[n][k] = pascal(n - 1, k - 1) + pascal(n - 1, k);
    return dp[n][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 31; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1;
        dp[i][i] = 1;
    }
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        cout << pascal(m, n) << '\n';
    }
}