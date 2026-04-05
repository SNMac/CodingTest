#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int t;
int input[100];

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (a % b == 0)
        return b;
    return gcd (b, a % b);
}

int main() {
    FAST_IO

    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        for (int j = 0; j < n; j++)
            cin >> input[j];

        unsigned long long total = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++)
                total += gcd(input[j], input[k]);
        }

        cout << total << '\n';
    }
}
