#include <iostream>
#include <vector>

using namespace std;

void reorder(vector<pair<int, int>> &v) {
    while (!(v[0].second == v[2].second + v[4].second && v[1].second == v[3].second + v[5].second)) {
        vector<pair<int, int>> temp;
        for (int i = 1; i <= 6; i++) {
            if (i == 6)
                temp.emplace_back(v[0].first, v[0].second);
            else
                temp.emplace_back(v[i].first, v[i].second);
        }
        v = temp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int, int>> v;
    int k;
    cin >> k;
    for (int i = 0; i < 6; i++) {
        int heading, meter;
        cin >> heading >> meter;
        v.emplace_back(heading, meter);
    }
    reorder(v);

    int area = v[0].second * v[1].second - v[3].second * v[4].second;
    cout << area * k << '\n';
}