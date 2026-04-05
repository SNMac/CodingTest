#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> v;
        for (int p = 0; p < n; p++) {
            int priority;
            cin >> priority;
            v.emplace_back(p, priority);
        }

        int order = 1;
        while(true) {
            for (int vIndex = 1; vIndex < v.size(); vIndex++) {
                if (v.front().second < v[vIndex].second) {
                    v.push_back(v.front());
                    v.erase(v.begin());
                    vIndex = 0;
                }
            }
            if (v.front().first != m) {
                v.erase(v.begin());
                order++;
            } else {
                cout << order << '\n';
                break;
            }
        }
    }
}