#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int answer = 0;

    for (int x = 1; x <= n - 1; x++) {
        int sum = 0;
        int temp = x;
        for (int i = 6; i >= 0; i--) {
            int power = (int)pow(10, i);
            sum += temp / power;
            temp %= power;
        }
        if (sum + x == n) {
            answer = x;
            break;
        }
    }
    cout << answer << '\n';
}