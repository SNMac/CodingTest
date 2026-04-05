#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

string input;
int bin[3] = {4, 2, 1};

int main() {
    FAST_IO

    cin >> input;

    while (input.length() % 3 != 0)
        input.insert(0, 1, '0');

    for (int i = 0; i < input.length(); i += 3) {
        int num = (input[i] - '0') * bin[i % 3]
                + (input[i + 1] - '0') * bin[(i + 1) % 3]
                + (input[i + 2] - '0') * bin[(i + 2) % 3];
        cout << num;
    }
    cout << '\n';
}
