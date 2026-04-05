#include <iostream>

using namespace std;

int* arr;

void swap(int i, int j) {
    while (i <= j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++; j--;
    }

}

int main() {
    int n, m;
    cin >> n >> m;
    arr = new int[n + 1];
    for (int p = 1; p <= n; p++) {
        arr[p] = p;
    }

    for (int p = 1; p <= m; p++) {
        int i, j;
        cin >> i >> j;
        swap(i, j);
    }

    for (int p = 1; p <= n; p++) {
        cout << arr[p] << ' ';
    }
    cout << '\n';
    delete[] arr;
}