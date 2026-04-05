#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        unordered_map<string, int> m;
        int n;
        cin >> n;
        cin.ignore();
        for (int j = 0; j < n; j++) {
            string input, cloth, kinds;
            getline(cin, input);
            kinds = input.substr(input.find(' ') + 1);
            if (m.find(kinds) == m.end()) {
                m.insert({kinds, 1});
            } else {
                m[kinds]++;
            }
        }

        int ans = 1;
        for (const auto& it : m)
            ans *= it.second + 1;
        ans--;
        cout << ans << '\n';
    }
}