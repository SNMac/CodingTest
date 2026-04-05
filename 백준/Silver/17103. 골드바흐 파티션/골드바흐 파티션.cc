#include <iostream>

#define MAX 1000001
using namespace std;

bool notPrime[MAX];

void primeInit() {
    notPrime[0] = notPrime[1] = true;
    for (int i = 2; i < MAX; i++) {
        if (!notPrime[i]) {
            for (int j = i + i; j < MAX; j += i)
                notPrime[j] = true;
        }
    }
}

int countGold(int n) {
    if (n == 4)
        return 1;

    int total = 0;
    for (int i = 3; i <= n / 2; i += 2) {
        if (!notPrime[i] & !notPrime[n - i])
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
