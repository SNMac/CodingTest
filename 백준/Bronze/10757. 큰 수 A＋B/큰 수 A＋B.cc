#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    string b;
    string c;
    cin >> a >> b;

    int len;
    if (a.length() > b.length()) {
        len = a.length();
        for (int i = b.length(); i < len; i++)
            b = '0' + b;
    } else if (a.length() < b.length()){
        len = b.length();
        for (int i = a.length(); i < len; i++)
            a = '0' + a;
    } else
        len = a.length();

    bool carry = false;
    for (int i = len - 1; i >= 0; i--) {
        int sum = (a[i] - 48) + (b[i] - 48);
        if (carry) {
            sum++;
            carry = false;
        }
        if (sum > 9) {
            carry = true;
            c.push_back((sum - 10) + 48);
        }
        else
            c.push_back(sum + 48);
    }
    if (carry)
        c.push_back(49);

    for (int i = c.length() - 1; i >= 0; i--)
        cout << c[i];
    cout << endl;
}