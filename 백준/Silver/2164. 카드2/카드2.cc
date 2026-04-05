#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    int powOfTwo = 1;
    while(powOfTwo < n)
        powOfTwo = powOfTwo << 1;
    powOfTwo = powOfTwo >> 1;
    int result = (n - powOfTwo) * 2;
    cout << result << '\n';
}