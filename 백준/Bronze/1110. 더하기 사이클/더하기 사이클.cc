#include <iostream>

using namespace std;

int main() {
    int n, ten, one, temp;
    cin >> n;
    int res = 0;
    int count = 0;
    if (n < 10) {
        ten = 0;
        one = n;
    } else {
        ten = n / 10;
        one = n % 10;
    }
    while(1) {
        temp = ten;
        ten = one;
        one += temp;
        if (one >= 10)
            one -= 10;
        res = ten * 10 + one;
        count++;
        if (res == n)
            break;
    }
    cout << count << endl;
}