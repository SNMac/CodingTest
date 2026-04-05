#include <iostream>

#define POW(n) n * n

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int totalPow = 0;
    for (int i = 0; i < 5; i++) {
        int input;
        cin >> input;
        totalPow += POW(input);
    }
    cout << totalPow % 10 << '\n';
}