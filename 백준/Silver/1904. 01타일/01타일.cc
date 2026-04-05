#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TIME_START chrono::steady_clock::time_point start_time = chrono::steady_clock::now();
#define TIME_END chrono::steady_clock::time_point end_time = chrono::steady_clock::now();
#define TIME_PRINT cout << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << "ms\n";
//#define DEBUG

#ifdef DEBUG
#include <chrono>
#endif

using namespace std;

int dp[1000001];

void solve(int n) {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
}

int main() {
    FAST_IO

    int N;
    cin >> N;

#ifdef DEBUG  // clock start
    TIME_START
#endif

    solve(N);
    cout << dp[N] << '\n';

#ifdef DEBUG  // clock end
    TIME_END
    TIME_PRINT
#endif

}
