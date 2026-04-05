#include <iostream>
#include <string>

using namespace std;

void search(string t, string w[], int wSize, int& count) {
    for (int i = 0; i < wSize; i++) {
        int index = t.find(w[i]);
        while (index != string::npos) {
            if (i == 7) {
                if (t[index - 1] == 'd') {
                    index = t.find(w[i], index + w[i].length());
                    continue;
                }
            }
            count -= w[i].length() - 1;
            index = t.find(w[i], index + w[i].length());
        }
    }
}

int main() {
    string words[8] = {"c=", "c-", "dz=", "d-",
                       "lj", "nj", "s=", "z="};
    string s;
    cin >> s;
    int count = s.length();
    search(s, words, 8, count);
    cout << count << endl;
}