#include <iostream>
#include <string>

using namespace std;

void cantor(int n, string& str) {
    int interval = 1;
    for (int i = 0; i < n - 1; i++)
        interval *= 3;

    if (n == 0) {
        str += '-';
        return;
    }
    cantor(n - 1, str);
    for (int i = 0; i < interval; i++)
        str += ' ';
    cantor(n - 1, str);
}

int main() {
    int N = 0;
    while (cin >> N) {
        string str;
        cantor(N, str);
        cout << str << '\n';
    }
}