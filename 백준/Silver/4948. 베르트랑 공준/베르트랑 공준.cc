#include <iostream>
#include <cmath>

using namespace std;

int main() {
    while(1) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        bool* arr = new bool[2 * n + 1];
        fill_n(arr, 2 * n + 1, true);

        arr[1] = false;
        for (int i = 2; i <= sqrt(2 * n); i++) {
            if (!arr[i])
                continue;
            for (int j = 1; i * j <= 2 * n; j++)
                arr[i * j] = false;
        }

        int count = 0;
        for (int i = n + 1; i < 2 * n + 1; i++) {
            if (arr[i])
                count++;
        }
        cout << count << '\n';
        delete[] arr;
    }
}