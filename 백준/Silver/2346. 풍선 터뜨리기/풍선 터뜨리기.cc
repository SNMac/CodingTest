#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[1000], result[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int dir, temp, arrIndex = 0, resIndex = 0;  // dir) 0 : <-, 1 : ->
    while (true) {
        temp = arr[arrIndex];
        arr[arrIndex] = 0;
        result[resIndex++] = arrIndex + 1;
        if (resIndex == n)
            break;

        if (temp < 0) {
            dir = 0;
            temp *= -1;
        } else {
            dir = 1;
        }

        for (int i = 0; i < temp; i++) {
            if (dir == 0) {  // <-
                if (--arrIndex == -1) {
                    arrIndex = n - 1;
                }
            } else {  // ->
                if (++arrIndex == n) {
                    arrIndex = 0;
                }
            }

            if (arr[arrIndex] == 0)
                i--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';
}
