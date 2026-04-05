#include <iostream>

using namespace std;

int main() {
    int a1, a0, c, n0;
    cin >> a1 >> a0;
    cin >> c;
    cin >> n0;
    if (a1 - c > 0) {
        cout << 0 << '\n';
    } else if (a1 - c == 0) {
        if (a0 > 0)
            cout << 0 << '\n';
        else
            cout << 1 << '\n';
    } else {  // a1 - c < 0
        if ((a1 - c) * n0 <= -a0)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}
