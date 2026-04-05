#include <iostream>
#include <cmath>

using namespace std;

unsigned long hashing(int l, const string& str) {
    int result = 0;
    for (int i = 0; i < l; i++)
        result += ((int)str[i] - 96) * (int)pow(31, i);
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