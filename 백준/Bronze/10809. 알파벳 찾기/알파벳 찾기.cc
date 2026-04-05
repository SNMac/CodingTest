#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int loc[26]; fill_n(loc, 26, -1);
    for (int i = 0; i < s.length(); i++) {
        if (loc[(int)s[i] - 97] != -1)
            continue;
        loc[(int)s[i] - 97] = i;
    }
    for (int i = 0; i < 26; i++)
        cout << loc[i] << " ";
    cout << endl;
}