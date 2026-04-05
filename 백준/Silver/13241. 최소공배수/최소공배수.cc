#include <iostream>

using namespace std;

long long int gcd(long long int a, long long int b) {
    long long int r = a % b;
    if (r == 0)
        return b;
    return gcd(b, r);
}

int main() {
    long long int a, b;
    cin >> a >> b;
    long long int temp = gcd(a, b);
    if (temp == 1) {
        cout << a * b << '\n';
    } else {
        cout << temp * (a / temp) * (b / temp) << '\n';
    }
}
