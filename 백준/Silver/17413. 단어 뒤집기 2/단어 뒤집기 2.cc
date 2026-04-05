#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int main() {
    FAST_IO

    string S, result;
    getline(cin, S);
    while (!S.empty()) {
        if (S.front() == '<') {
            result += (S.substr(0, S.find('>') + 1));
            S = S.substr(S.find('>') + 1);
        } else {
            int space_idx = S.find(' ');
            int tag_idx = S.find('<');
            if (space_idx == string::npos) {
                if (tag_idx == string::npos) {
                    for (int i = S.length() - 1; i >= 0; i--)
                        result += S[i];
                    S.erase(0);
                } else {  // tag_idx != string::npos
                    for (int i = tag_idx - 1; i >= 0; i--)
                        result += S[i];
                    S.erase(0, tag_idx);
                }
            } else {  // space_idx != string::npos
                if (tag_idx == string::npos) {
                    for (int i = space_idx - 1; i >= 0; i--)
                        result += S[i];
                    result += ' ';
                    S.erase(0, space_idx + 1);
                } else {  // tag_idx != string::npos
                    if (space_idx < tag_idx) {
                        for (int i = space_idx - 1; i >= 0; i--)
                            result += S[i];
                        result += ' ';
                        S.erase(0, space_idx + 1);
                    } else {  // tag_idx <= space_idx
                        for (int i = tag_idx - 1; i >= 0; i--)
                            result += S[i];
                        S.erase(0, tag_idx);
                    }
                }
            }
        }
    }
    cout << result << '\n';
}
