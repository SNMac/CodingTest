#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    int j = input.length() - 1;
    for (int i = 0; i < input.length() / 2; i++) {
        if (input[i] != input[j]) {
            cout << 0;
            return 0;
        }
        j--;
    }
    cout << 1;
}
