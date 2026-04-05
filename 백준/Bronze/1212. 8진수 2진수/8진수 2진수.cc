#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

string octal;

int main() {
    FAST_IO

    cin >> octal;
    if (octal == "0") {
        cout << '0' << '\n';
        return 0;
    }

    for (int i = 0; i < octal.length(); i++) {
        int digit = octal[i] - '0';
        int bin[3];

        if (digit / 4) {
            bin[2] = 1;
            digit %= 4;
        } else {
            bin[2] = 0;
        }

        if (digit / 2) {
            bin[1] = 1;
            digit %= 2;
        } else {
            bin[1] = 0;
        }

        if (digit) {
            bin[0] = 1;
        } else {
            bin[0] = 0;
        }

        if (i == 0) {
            if (bin[2]) {
                cout << bin[2] << bin[1] << bin[0];
            } else if (bin[1]) {
                cout << bin[1] << bin[0];
            } else {
                cout << bin[0];
            }
        } else {
            cout << bin[2] << bin[1] << bin[0];
        }
    }
}
