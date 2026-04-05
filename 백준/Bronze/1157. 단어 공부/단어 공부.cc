#include <iostream>
#include <string>

using namespace std;

int main() {
    string w;
    cin >> w;
    int freq[26] = {0, };
    for (int i = 0; i < w.length(); i++)
        freq[toupper(w[i]) - 65]++;

    int mfreq = 0;
    bool equal = false;
    for (int i = 1; i < 26; i++) {
        if (freq[i] > freq[mfreq]) {
            mfreq = i;
            equal = false;
        }
        else if (freq[i] == freq[mfreq]) {
            if (freq[i] != 0)
                equal = true;
        }
    }
    if (equal)
        cout << '?' << endl;
    else
        cout << (char)(mfreq + 65) << endl;
}