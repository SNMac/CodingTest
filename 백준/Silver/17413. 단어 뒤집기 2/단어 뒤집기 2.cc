#include <iostream>
#include <string>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int main() {
    FAST_IO

    string S, result;
    getline(cin, S);

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '<') {
            i = S.find('>', i);
        } else {  // S[i] == character
            int tag_idx = S.find('<', i);
            if (tag_idx != string::npos) {
                int space_idx = S.find(' ', i);
                if (space_idx != string::npos) {
                    if (space_idx < tag_idx) {
                        reverse(S.begin() + i, S.begin() + space_idx);
                        i = space_idx;
                    } else {  // tag_idx <= space_idx
                        reverse(S.begin() + i, S.begin() + tag_idx);
                        i = S.find('>', i);
                    }
                } else {  // space_idx == string::npos
                    reverse(S.begin() + i, S.begin() + tag_idx);
                    i = S.find('>', i);;
                }
            } else {  // tag_idx == string::npos
                int space_idx = S.find(' ', i);
                if (space_idx != string::npos) {
                    reverse(S.begin() + i, S.begin() + space_idx);
                    i = space_idx;
                } else {  // space_idx == string::npos
                    reverse(S.begin() + i, S.end());
                    break;
                }
            }
        }
    }
    cout << S << '\n';
}
