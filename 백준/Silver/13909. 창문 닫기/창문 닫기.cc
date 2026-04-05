#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, i;
    cin >> n;
    for (i = 1; i * i < n; i++);
    if (n / i == i) {
        cout << i << '\n';
    } else {
        cout << i - 1 << '\n';
    }
}
