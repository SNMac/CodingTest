#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++) {
        string str;
        getline(cin, str);
        cout << str.front() << str.back() << '\n';
    }
}