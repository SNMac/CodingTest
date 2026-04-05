#include <iostream>
#include <string>
#include <set>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

string input;
set<string> s;

int main() {
    FAST_IO

    getline(cin, input);

    for (int i = 0; i < input.length(); i++)
        s.insert(input.substr(i, input.length() - i));

    for (auto& it : s)
        cout << it << '\n';
}
