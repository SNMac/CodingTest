#include <iostream>

using namespace std;

int prime[1000001];

void primeInit() {
    prime[0] = 0; prime[1] = 0;
    for (int i = 2; i < 1000001; i++)
        prime[i] = i;

    for (int i = 2; i < 1000001; i++) {
        if (prime[i] == 0)
            continue;

        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {  // 소수 판별
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            for (int j = i + i; j < 1000001; j += i) {
                prime[j] = 0;
            }
        }
    }
}

int countGold(int n) {
    int total = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (prime[i] && prime[n - i])
            total++;
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    primeInit();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << countGold(n) << '\n';
    }
}