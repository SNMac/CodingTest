#include <iostream>

#define MAX 1000001
using namespace std;

bool prime[MAX];

void primeInit() {
    fill_n(prime, MAX, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAX; i++) {
        if (!prime[i])
            continue;

        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {  // 소수 판별
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            for (int j = i + i; j < MAX; j += i) {
                prime[j] = false;
            }
        }
    }
}

int countGold(int n) {
    int total = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (prime[i] & prime[n - i])
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
