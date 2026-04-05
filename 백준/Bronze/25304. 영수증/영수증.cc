#include <iostream>

using namespace std;

int main() {
    int x, n, a, b;
    int total = 0;
    cin >> x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        total += a * b;
    }
    if (x == total)
        cout << "Yes" << endl;
    else
        cout <<"No" << endl;
}