#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> v;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    vector<string> result;
    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        auto iter = binary_search(v.begin(), v.end(), input);
        if (iter)
            result.push_back(input);
    }
    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (const auto& iter : result)
        cout << iter << '\n';
}