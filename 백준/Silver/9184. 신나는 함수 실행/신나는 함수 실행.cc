#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
//#define DEBUG

using namespace std;
#ifdef DEBUG
#include <chrono>
using namespace chrono;
#endif

int dp[21][21][21];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return dp[0][0][0];
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    if (dp[a][b][c] != 0)
        return dp[a][b][c];
    if (a < b && b < c) {
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return dp[a][b][c];
    }

    dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b , c - 1)
                  - w(a - 1, b - 1, c - 1);
    return dp[a][b][c];
}

int main() {
    FAST_IO

    dp[0][0][0] = 1;
    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
#ifdef DEBUG  // clock start
        steady_clock::time_point start_time = steady_clock::now();
#endif
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
#ifdef DEBUG  // clock end
        steady_clock::time_point end_time = steady_clock::now();
        milliseconds mill = duration_cast<milliseconds>(end_time - start_time);
        cout << mill.count() << "ms" << '\n';
#endif
    }
}
