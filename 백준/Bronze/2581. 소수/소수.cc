#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m;
    cin >> n;

    int sum = 0, min = -1;
    for (int i = m; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0)
                count++;
            if (count > 2)
                break;
        }
        if (count == 2) {
            if (min == -1)
                min = i;
            sum += i;
        }
    }
    if (sum == 0)
        cout << min << endl;
    else
        cout << sum << '\n' << min << endl;

}