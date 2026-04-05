#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int main() {
    FAST_IO

    int T;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        string input;
        getline(cin, input);
        int idx = input.find(' ');
        while(idx != string::npos) {
            input.erase(idx, 1);
            for (idx -= 1; idx >= 0; idx--) {
                cout << input[idx];
                input.erase(idx, 1);
            }
            cout << ' ';
            idx = input.find(' ');
        }
        for (int c = input.length() - 1; c >= 0; c--)  // 마지막 단어
            cout << input[c];
        cout << '\n';
    }
}
