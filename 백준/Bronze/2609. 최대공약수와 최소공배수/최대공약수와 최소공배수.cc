#include <iostream>

using namespace std;

int LCM(int a, int b) {
    int ta = a, tb = b;
    while (ta != tb) {
        if (ta < tb)
            ta += a;
        else if (ta > tb)
            tb += b;
    }
    return ta;
}

int GCD(int a, int b) {
    while (a != b) {
        if (a < b)
            b = b - a;
        else if (a > b)
            a = a - b;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    cout << GCD(a, b) << '\n';
    cout << LCM(a, b) << '\n';
}