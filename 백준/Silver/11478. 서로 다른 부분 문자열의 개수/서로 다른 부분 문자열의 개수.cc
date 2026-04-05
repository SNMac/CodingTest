#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    unordered_set<string> part;
    int len = 1;
    while(len <= s.length()) {
        for (int i = 0; i < s.length(); i++) {
            if (i + len > s.length())
                break;
            part.insert(s.substr(i, len));
        }
        len++;
    }
    cout << part.size() << '\n';
}