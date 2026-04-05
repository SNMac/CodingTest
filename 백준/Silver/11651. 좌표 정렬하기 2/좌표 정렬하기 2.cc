#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> v1, pair<int, int> &v2) {
    if (v1.second == v2.second)
        return v1.first < v2.first;
    else
        return v1.second < v2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << ' ' << v[i].second << '\n';
}