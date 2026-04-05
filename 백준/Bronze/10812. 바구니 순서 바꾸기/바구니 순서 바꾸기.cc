#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v;

    for (int a = 1; a <= n; a++)
        v.push_back(a);

    for (int a = 0; a < m; a++) {
        int i, j, k;
        cin >> i >> j >> k;
        rotate(v.begin() + (i - 1), v.begin() + (k - 1), v.begin() + j);
    }

    for (int it : v) {
        cout << it << ' ';
    }
    cout << '\n';
}