#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    vector<int> ov(n);
    for (int i = 0; i < n; i++)
        cin >> ov[i];
    sort(ov.begin(), ov.end());

    cin >> m;
    vector<int> cv(m);
    for (int i = 0; i < m; i++)
        cin >> cv[i];

    for (int i = 0; i < m; i++) {
        int hIndex = ov.size() - 1, lIndex = 0;
        bool found = false;
        while(lIndex <= hIndex) {
            int mIndex = (hIndex + lIndex) / 2;
            if (cv[i] > ov[mIndex])
                lIndex = mIndex + 1;
            else if (cv[i] < ov[mIndex])
                hIndex = mIndex - 1;
            else {
                found = true;
                break;
            }
        }
        if (found)
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
}