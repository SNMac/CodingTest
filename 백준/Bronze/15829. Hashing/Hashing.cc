#include <iostream>

#define M 1234567891

using namespace std;

long long hashing(int l, const string& str) {
    long long result = 0;
    long long r = 1;
    for (int i = 0; i < l; i++) {
        result = result + ((str[i] - 'a' + 1) * r) % M;
        r = (r * 31) % M;
    }
    return result;
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