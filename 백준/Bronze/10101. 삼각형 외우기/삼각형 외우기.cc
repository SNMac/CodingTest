#include <iostream>

using namespace std;

int main() {
    int a, b, c, total;
    cin >> a >> b >> c;
    total = a + b + c;
    if (total == 180) {
        if (a == b && b == c) {
          cout << "Equilateral" << '\n';
        } else if (a == b || a == c || b == c) {
            cout << "Isosceles" << '\n';
        } else {
            cout << "Scalene" << '\n';
        }
    } else {
        cout << "Error" << '\n';
    }
}
