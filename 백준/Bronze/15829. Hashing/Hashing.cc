#include <iostream>

using namespace std;

unsigned long long hashing(int l, const string& str) {
    unsigned long long result = 0;
    unsigned long long m = 1;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < i; j++)
            m *= 31;
        result += (str[i] - 'a' + 1) * m;
        m = 1;
    }
    return result % 1234567891;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l;
    string str;
    cin >> l;
    cin >> str;
    cout << hashing(l, str) << '\n';
}