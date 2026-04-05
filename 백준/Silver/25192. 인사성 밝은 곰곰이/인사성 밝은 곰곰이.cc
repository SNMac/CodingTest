#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string> s;
    int n;
    cin >> n;
    cin.ignore();
    string input;

    int total = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, input);
        if (input == "ENTER") {
            total += s.size();
            s.clear();
            continue;
        }
        s.insert(input);
    }
    total += s.size();
    cout << total << '\n';
}
