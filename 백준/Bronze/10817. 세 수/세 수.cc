#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a >= b) {
        if (b >= c)
            cout << b << endl;
        else {  // c > b
            if (a >= c)
                cout << c << endl;
            else
                cout << a << endl;
        }
    } else {  // b > a
        if (a >= c)
            cout << a << endl;
        else {  // c > a
            if (b >= c)
                cout << c << endl;
            else
                cout << b << endl;
        }
    }
}