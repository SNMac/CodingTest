#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;

    if (k > n / 2)
        k = n - k;
    int up = 1, down = 1;
    for (int i = 1; i <= k; i++) {
        up *= n--;
        down *= i;
    }
    cout << up / down << '\n';
}