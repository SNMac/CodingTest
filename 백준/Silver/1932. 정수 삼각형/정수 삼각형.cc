#include <iostream>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int n;
int dp[501][501];

int main() {
    FAST_IO

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int input;
            cin >> input;  // 현재층 숫자 입력
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + input;  // 위층 숫자 더함
        }
    }
    cout << *max_element(dp[n], dp[n] + n + 1) << '\n';
}
