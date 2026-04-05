#include <iostream>

using namespace std;

int main() {
    int max = 0;
    int maxX = 1, maxY = 1;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int input;
            cin >> input;
            if (input > max) {
                max = input;
                maxX = j;
                maxY = i;
            }
        }
    }
    cout << max << '\n' << maxY << ' ' << maxX << '\n';
}