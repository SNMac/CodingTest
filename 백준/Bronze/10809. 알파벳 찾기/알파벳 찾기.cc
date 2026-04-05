#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

string input;
int alpha[26];

int main() {
    FAST_IO

    fill_n(alpha, 26, -1);
    getline(cin, input);
    for (int i = 0; i < input.length(); i++) {
        if (alpha[input[i] - 'a'] == -1)
            alpha[input[i] - 'a'] = i;
    }

    for (int i : alpha)
        cout << i << ' ';
    cout << '\n';
}
