#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    if (m == 1)
        m++;

    for (int i = m; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0)
                count++;
            if (count > 1)
                break;
        }
        if (count == 1)
            cout << i << '\n';
    }
}