#include <iostream>
#include <limits>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int arr[100000];
int dp[100000];

int solve(int n) {
    int ret = numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dp[i] = arr[i];
        } else {
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        }
        ret = max(ret, dp[i]);
    }
    return ret;
}

int main() {
    FAST_IO

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << solve(n) << '\n';
}
