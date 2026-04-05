#include <iostream>
#include <string>

using namespace std;

void swap(string& s) {
    char temp;
    temp = s[0];
    s[0] = s[2];
    s[2] = temp;
}

int main() {
    string a, b;
    cin >> a >> b;
    swap(a);
    swap(b);
    if (stoi(a) > stoi(b))
        cout << a << endl;
    else
        cout << b << endl;
}