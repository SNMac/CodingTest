#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

string octal;
string binary;

int main() {
    FAST_IO

    cin >> octal;
    if (octal == "0") {
        cout << '0' << '\n';
        return 0;
    }

    for (int i = 0; i < octal.length(); i++) {
        int digit = octal[i] - '0';

        if (digit / 4) {
            binary += '1';
            digit %= 4;
        } else {
            binary += '0';
        }

        if (digit / 2) {
            binary += '1';
            digit %= 2;
        } else {
            binary += '0';
        }

        if (digit) {
            binary += '1';
        } else {
            binary += '0';
        }
    }

    while (binary[0] == '0')
        binary.erase(0, 1);
    cout << binary << '\n';
}
