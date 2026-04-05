#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

string input;
int lower, upper, digit, space;

int main() {
    FAST_IO

    while (getline(cin, input)) {

        for (int i = 0; i < input.length(); i++) {
            if (islower(input[i])) {
                lower++;
            } else if (isupper(input[i])) {
                upper++;
            } else if (isdigit(input[i])) {
                digit++;
            } else if (input[i] == ' ') {
                space++;
            }
        }

        cout << lower << ' ' << upper << ' ' << digit << ' ' << space << '\n';
        lower = upper = digit = space = 0;
    }
}
