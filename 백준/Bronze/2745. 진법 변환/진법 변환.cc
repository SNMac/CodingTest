#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    int b;
    cin >> n >> b;

    int total = 0;
    for (int i = n.length() - 1; i >= 0; i--) {
        int temp = 1;
        for (int j = 0; j < i; j++) {
            temp *= b;
        }
        int nowIndex = n.length() - 1 - i;
        if (isalpha(n[nowIndex])) {
            temp *= n[nowIndex] - 'A' + 10;
        } else {
            temp *= n[nowIndex] - '0';
        }
        total += temp;
    }
    cout << total << '\n';
}
