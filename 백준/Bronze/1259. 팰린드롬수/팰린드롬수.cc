#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true) {
        int input;
        cin >> input;
        if (input == 0)
            break;
        int number[5];
        int n = 0;
        while(input != 0) {
            number[n] = input % 10;
            input /= 10;
            n++;
        }
        n--;
        int i = 0;
        bool isPalin = true;
        while(i < n) {
            if (number[i] != number[n]) {
                isPalin = false;
                break;
            }
            i++; n--;
        }
        if (isPalin)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}