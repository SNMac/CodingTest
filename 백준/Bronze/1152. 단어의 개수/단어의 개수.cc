#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int count;
    getline(cin, s);
    if (s.length() > 0)
        count = 1;
    else
        count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (i == 0)
                count--;
            if (i != s.length() - 1) {
                count++;
            }
        }
    }
    cout << count << endl;
}