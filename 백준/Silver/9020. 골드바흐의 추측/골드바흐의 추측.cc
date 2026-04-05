#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        bool* prime = new bool[n + 1];
        fill_n(prime, n + 1, true);

        prime[1] = false;
        for (int a = 2; a <= sqrt(n); a++) {
            if (!prime[a])
                continue;
            for (int b = 2; b * a <= n; b++)
                prime[a * b] = false;
        }

        bool brk = false;
        for (int l = n / 2; l >= 2; l--) {
            if (brk)
                break;
            if (!prime[l])
                continue;
            for (int r = n / 2; r <= n; r++) {
                if (!prime[r])
                    continue;
                if (l + r == n) {
                    cout << l << ' ' << r << '\n';
                    brk = true;
                    break;
                }
            }
        }
        delete[] prime;
    }
}