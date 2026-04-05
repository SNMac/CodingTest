#include <iostream>
#include <cmath>

using namespace std;

void hansu(int num, int& cnt) {
    int digit[4];
    int digitCount = 0;
    int temp = num;
    for (int k = 3; k >= 0; k--) {
        digit[k] = temp / (int)pow(10, k);
        if (digitCount == 0 && digit[k] != 0)
            digitCount = k + 1;
        temp %= (int)pow(10, k);
    }
    if (digitCount == 1 || digitCount == 2)
        cnt++;
    else if (digitCount == 3) {
        if (digit[1] - digit[0] == digit[2] - digit[1])
            cnt++;
    }
    else {
        if (digit[1] - digit[0] == digit[2] - digit[1]
        && digit[2] - digit[1] == digit[3] - digit[2])
            cnt++;
    }
}

int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        hansu(i, count);
    }
    cout << count << endl;
}