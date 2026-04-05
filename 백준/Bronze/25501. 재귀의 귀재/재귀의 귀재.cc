#include <iostream>

using namespace std;

int recursion(string &s, int l, int r, int &recurCount){
    if(l >= r)
        return 1;
    else if(s[l] != s[r])
        return 0;
    else {
        recurCount++;
        return recursion(s, l + 1, r - 1, recurCount);
    }
}

int isPalindrome(string &s, int &recurCount){
    return recursion(s, 0, s.length() - 1, recurCount);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        int recurCount = 1;
        cout << isPalindrome(s, recurCount) << ' ' << recurCount << '\n';
    }
}