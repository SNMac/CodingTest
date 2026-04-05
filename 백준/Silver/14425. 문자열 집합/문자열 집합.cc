#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> nv(n);
    for (int i = 0; i < n; i++)
        cin >> nv[i];
    sort(nv.begin(), nv.end());

    vector<string> mv(m);
    for (int i = 0; i < m; i++)
        cin >> mv[i];

    int result = 0;
    for (int i = 0; i < m; i++) {
        if (binary_search(nv.begin(), nv.end(), mv[i]))
            result++;
    }
    cout << result << '\n';
}