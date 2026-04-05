#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b >= c) {
        cout << -1 << endl;
        return 0;
    }
    long count = a / (c - b);
    if (a % (c - b) == 0 || a % (c - b) >= 0.5)
        count++;
    cout << count << endl;
}