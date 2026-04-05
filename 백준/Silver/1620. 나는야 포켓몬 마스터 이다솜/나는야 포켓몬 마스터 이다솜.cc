#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> pVec(n);
    unordered_map<string, int> pMap;
    for (int i = 1; i <= n; i++) {
        string input;
        cin >> input;
        pMap.insert({input, i});
        pVec[i - 1] = input;
    }

    for (int i = 0; i < m; i++) {
        string cmp;
        cin >> cmp;
        if (isdigit(cmp[0]))
            cout << pVec[stoi(cmp) - 1] << '\n';
        else
            cout << pMap[cmp] << '\n';
    }
}