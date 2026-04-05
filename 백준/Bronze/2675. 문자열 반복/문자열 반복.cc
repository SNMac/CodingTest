#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int r;
        string s;
        cin >> r >> s;
        for (int a = 0; a < s.length(); a++) {
            for (int b = 0; b < r; b++) {
                cout << s[a];
            }
        }
        cout << endl;
    }
}