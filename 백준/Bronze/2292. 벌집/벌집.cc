#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int a = 2;
    int b = 7;
    int count = 2;
    while(1) {
        if (n >= a && n <= b)
            break;
        else {
            a += (count - 1) * 6;
            b += count * 6;
            count++;
        }
    }
    cout << count << endl;
}