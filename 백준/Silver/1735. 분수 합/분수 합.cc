#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int r = a % b;
    if (r == 0) {
        return b;
    }
    return gcd(b, r);
}

int main() {
    int a1, b1, a2, b2, ar, br;
    cin >> a1 >> b1;
    cin >> a2 >> b2;

    ar = a1 * b2 + a2 * b1;
    br = b1 * b2;
    int t = gcd(ar, br);
    ar /= t;
    br /= t;
    cout << ar << ' ' << br << '\n';
}
