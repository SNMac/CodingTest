#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int, int>> v;
    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());

    if (v[0].first == v[1].first) {
        cout << v[2].first << ' ';
        if (v[0].second == v[2].second)
            cout << v[1].second << '\n';
        else
            cout << v[0].second << '\n';
    } else {
        cout << v[0].first << ' ';
        if (v[0].second == v[1].second)
            cout << v[2].second << '\n';
        else
            cout << v[1].second << '\n';
    }
}