#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bool arr[1001] = {false, };
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        arr[i] = true;

    cout << '<';
    int order = 1, i = 1, alive = n;
    while(alive) {
        if (arr[i]) {
            if (order % k == 0) {
                cout << i;
                order = 1;
                arr[i] = false;
                if (--alive == 0)
                    cout << '>';
                else
                    cout << ", ";
            } else {
                order++;
            }
        }
        if (++i > n)
            i = 1;
    }
}