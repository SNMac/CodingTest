#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    if (x == 1) {
        cout << "1/1" << endl;
        return 0;
    }
    int up = 1;
    int down = 2;
    int sum = 3;
    int count = 2;
    while (count < x) {
        if (sum % 2 == 1) {
            if (up + 1 == sum) {
                sum++;
                up++;
            } else {
                down--;
                up++;
            }

        }
        else {
            if (down + 1 == sum) {
                sum++;
                down++;
            } else {
                up--;
                down++;
            }
        }
        count++;
    }
    cout << up << '/' << down << endl;
}