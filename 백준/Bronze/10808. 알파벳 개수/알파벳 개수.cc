#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

string input;
int alpha[26];

int main() {
    FAST_IO

    getline(cin, input);
    for (char c : input)
        alpha[c - 'a']++;

    for (int i : alpha)
        cout << i << ' ';
    cout << '\n';
}
