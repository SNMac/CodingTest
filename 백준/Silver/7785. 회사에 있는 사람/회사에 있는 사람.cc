#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    set<string, greater<string>> s;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string input, name, log;
        getline(cin, input);
        name = input.substr(0, input.find(' '));
        log = input.substr(input.find(' ') + 1);
        if (log == "enter") {
            s.insert(name);
        } else {
            s.erase(name);
        }
    }
    for (auto& it : s)
        cout << it << '\n';
}
