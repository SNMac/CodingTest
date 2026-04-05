#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    for (int i = m; i <= n; i++) {
        if (i == 1)
            continue;
        int count = 0;
        bool prime = true;
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                if (count == 0)
                    count++;
                else {
                    prime = false;
                    break;
                }
            }
        }
        if (prime)
            cout << i << '\n';
    }
}