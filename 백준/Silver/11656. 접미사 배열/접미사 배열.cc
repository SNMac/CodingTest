#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

string input;
vector<string> v;

int main() {
    FAST_IO

    getline(cin, input);

    for (int i = 0; i < input.length(); i++)
        v.push_back(input.substr(i, input.length() - i));
    sort(v.begin(), v.end());

    for (string& str : v)
        cout << str << '\n';
}
