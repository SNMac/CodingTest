#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        cout << upper_bound(v.begin(), v.end(), input)
        - lower_bound(v.begin(), v.end(), input) << ' ';
    }
}