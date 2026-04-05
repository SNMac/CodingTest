#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int valid = 0;
        string str;
        cin >> str;
        for (char j : str) {
            if (j == '(')
                valid++;
            else if (j == ')') {
                if (--valid < 0)
                    break;
            }
        }
        if (!valid)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}