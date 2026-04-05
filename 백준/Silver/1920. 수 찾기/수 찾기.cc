#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    int* nArr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> nArr[i];
    sort(nArr, nArr + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (binary_search(nArr, nArr + n, x))
            cout << 1;
        else
            cout << 0;
        cout << '\n';
    }
    delete[] nArr;
}