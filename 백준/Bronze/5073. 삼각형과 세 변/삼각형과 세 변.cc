#include <iostream>

using namespace std;

int main() {
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;

        if (a == b && b == c) {
            cout << "Equilateral" << '\n';
            continue;
        } else if (a >= b && a >= c) {  // max = a
            if (a >= (b + c)) {
                cout << "Invalid" << '\n';
                continue;
            }
        } else if (b >= a && b >= c) {  // max = b
            if (b >= (a + c)) {
                cout << "Invalid" << '\n';
                continue;
            }
        } else if (c >= a && c >= b) {  // max = c
            if (c >= (a + b)) {
                cout << "Invalid" << '\n';
                continue;
            }
        }

        if (a == b || b == c || a == c) {
            cout << "Isosceles" << '\n';
        } else {
            cout << "Scalene" << '\n';
        }
    }
}
