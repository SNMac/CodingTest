#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0 ; i < n; i++) {
        bool alpha[26] = {0, };
        bool group = true;
        int cont;
        string word;
        cin >> word;
        for (int l = 0; l < word.length(); l++) {
            if (!alpha[word[l] - 97]) {
                alpha[word[l] - 97] = true;
                cont = word[l] - 97;
            } else if (cont == word[l] - 97) {
                continue;
            } else {
                group = false;
                break;
            }
        }
        if (group)
            count++;
    }
    cout << count << endl;
}