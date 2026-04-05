#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int num = 665;
    int count = 0;

    while(count != n) {
        num++;
        int temp = num;
        while (temp) {
            if (temp % 1000 == 666) {
                count++;
                break;
            } else {
                temp /= 10;
            }
        }
    }
    cout << num << '\n';
}