#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    string total;
    while (n != 0) {
        int r = n % b;
        if (r >= 10) {
            total.insert(0, 1, (char)('A' + r - 10));
        } else {
            total.insert(0, to_string(r));
        }
        n /= b;
    }
    cout << total << '\n';
}
