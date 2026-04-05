#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

string input;

int main() {
    FAST_IO

    getline(cin, input);

    for (char& c : input) {
        if (islower(c)) {
            c = c - 'a' + 13;
            if (c >= 26)
                c -= 26;
            c += 'a';
        } else if (isupper(c)) {
            c = c - 'A' + 13;
            if (c >= 26)
                c -= 26;
            c += 'A';
        }
    }

    cout << input << '\n';
}
