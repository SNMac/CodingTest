#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int r = a % b;
    if (!r)
        return b;
    return gcd(b, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        int G = gcd(a, b);
        cout << a * b / G << '\n';
    }
}