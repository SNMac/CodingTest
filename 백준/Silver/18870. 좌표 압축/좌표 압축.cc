#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(make_pair(x, i));
    }

    sort(v.begin(), v.end());
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i != n - 1 && v[i].first == v[i + 1].first) {
            v[i].first = count;
            continue;
        }
        v[i].first = count;
        count++;
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
        cout << v[i].first << ' ';
    cout << '\n';
}