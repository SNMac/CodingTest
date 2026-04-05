#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, b;
    cin >> n >> m >> b;
    vector<int> v;
    int min = 256, MAX = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int h;
            cin >> h;
            v.push_back(h);
            if (h < min)
                min = h;
            if (h > MAX)
                MAX = h;
        }
    }

    vector<pair<int, int>> result;  // time, height, needed blocks
    for (int k = min; k <= MAX; k++) {
        int time = 0, rmBlocks = 0, fillBlocks = 0;
        for (auto it : v) {
            if (it - k > 0) {
                time += 2 * (it - k);
                rmBlocks += it - k;
            } else if (it - k < 0) {
                time += k - it;
                fillBlocks += k - it;
            }
        }
        if (b + rmBlocks >= fillBlocks)
            result.emplace_back(time, k);
    }

    sort(result.begin(), result.end());
    int resultT = result[0].first, resultH = result[0].second;
    for (auto it : result) {
        if (resultT == it.first) {
            if (resultH < it.second)
                resultH = it.second;
        } else {
            break;
        }
    }
    cout << resultT << ' ' << resultH << '\n';
}