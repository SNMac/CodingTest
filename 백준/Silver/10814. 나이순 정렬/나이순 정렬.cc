#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const tuple<int, string, int> &a, const tuple<int, string, int> &b) {
    if (get<0>(a) == get<0>(b))
        return get<2>(a) < get<2>(b);
    else
        return get<0>(a) < get<0>(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<tuple<int, string, int>> v;
    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(make_tuple(age, name, i));
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
        cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << '\n';
}