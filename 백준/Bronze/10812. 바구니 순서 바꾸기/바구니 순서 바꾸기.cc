#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v;
    v.push_back(0);

    for (int a = 1; a <= n; a++)
        v.push_back(a);

    for (int a = 0; a < m; a++) {
        vector<int> tempV;
        int i, j, k;
        cin >> i >> j >> k;
        for (int b = i; b <= j; b++)
            tempV.push_back(v[b]);
        rotate(tempV.begin(), tempV.begin() + (k - i), tempV.end());
        int tempIndex = 0;
        for (int b = i; b <= j; b++)
            v[b] = tempV[tempIndex++];
    }

    for (int i = 1; i <= n; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}