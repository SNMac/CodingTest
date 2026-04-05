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

unsigned long long dp[1000001];

unsigned long long solve(int n) {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] % 15746 + dp[i - 2] % 15746) % 15746;
    return dp[n];
}

int main() {
    FAST_IO

    int N;
    cin >> N;

#ifdef DEBUG  // clock start
    TIME_START
#endif

    cout << solve(N) % 15746 << '\n';

#ifdef DEBUG  // clock end
    TIME_END
    TIME_PRINT
#endif

}
