#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int answer = 0;
    for (int x = 1; x <= n - 1; x++) {
        int sum = x;
        int temp = x;
        while(temp) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == n) {
            answer = x;
            break;
        }
    }
    cout << answer << '\n';
}