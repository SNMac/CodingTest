#include <iostream>

#define MAX 1000001
using namespace std;

bool notPrimeArr[MAX];

void primeInit() {
    notPrimeArr[0] = notPrimeArr[1] = true;
    for (int i = 2; i < MAX; i++) {
        if (notPrimeArr[i])
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
                notPrimeArr[j] = true;
            }
        }
    }
}

int countGold(int n) {
    int total = 0;
    for (int i = 2; i <= n / 2; i++) {
        if (!notPrimeArr[i] & !notPrimeArr[n - i])
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
