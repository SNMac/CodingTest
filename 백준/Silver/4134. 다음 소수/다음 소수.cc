#include <iostream>

using namespace std;

long long findPrime(long long n) {
    if (n <= 2)
        return 2;

    long long i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            n++;
            i = 2;
            continue;
        }
        i++;
    }
    return n;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        cout << findPrime(n) << '\n';
    }
}