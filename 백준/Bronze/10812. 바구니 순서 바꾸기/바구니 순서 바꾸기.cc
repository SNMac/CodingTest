#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int* arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
        arr[i] = i;

    for (int r = 0; r < m; r++) {
        int i, j, k;
        cin >> i >> j >> k;
        vector<int> v;
        int vIndex = 0;
        int begin = i, end = j, repeat = j - i + 1;

        for (int s = 0; s < repeat; s++) {
            v.push_back(arr[begin]);
            if (k > end)
                arr[begin++] = v[vIndex++];
            else {
                arr[begin++] = arr[k++];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    delete[] arr;
}