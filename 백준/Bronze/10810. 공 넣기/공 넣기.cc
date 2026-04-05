#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int* arr = new int[n + 1];

    for (int p = 1; p <= m; p++) {
        int i, j, k;
        cin >> i >> j >> k;
        for (; i <= j; i++) {
            arr[i] = k;
        }
    }
    for (int p = 1; p <= n; p++)  {
        cout << arr[p] << ' ';
    }
    cout << '\n';
    delete[] arr;
}