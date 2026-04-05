#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> pVec;
unordered_map<string, int> pMap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string input;
        cin >> input;
        pMap.insert({input, i});
        pVec.push_back(input);
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