#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> ov;
    vector<int> cv;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int o_input;
        cin >> o_input;
        ov.push_back(o_input);
    }
    sort(ov.begin(), ov.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        int c_input;
        cin >> c_input;
        cv.push_back(c_input);
    }

    for (int i = 0; i < m; i++) {
        auto cmp = binary_search(ov.begin(), ov.end(), cv[i]);
        if (cmp)
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
}