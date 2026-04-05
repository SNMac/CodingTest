#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    vector<int> ov(n);
    for (int i = 0; i < n; i++)
        cin >> ov[i];
    sort(ov.begin(), ov.end());

    cin >> m;
    vector<int> cv(m);
    for (int i = 0; i < m; i++)
        cin >> cv[i];

    for (int i = 0; i < m; i++) {
        auto cmp = binary_search(ov.begin(), ov.end(), cv[i]);
        if (cmp)
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
}