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

    string input;
    int result = 0;
    for (int i = 0; i < m; i++) {
        cin >> input;
        if (binary_search(nv.begin(), nv.end(), input))
            result++;
    }

    cout << result << '\n';
}