#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    string str;
    for (int i = 0; i < t; i++) {
        cin >> str;
        int point = 1;
        int score = 0;
        for (int n = 0; n < str.length(); n++) {
            if (str[n] == 'O') {
                score += point;
                point++;
            } else if (str[n] == 'X')
                point = 1;
        }
        cout << score << endl;
    }
}