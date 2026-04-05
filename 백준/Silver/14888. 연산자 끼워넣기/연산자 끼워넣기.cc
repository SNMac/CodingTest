#include <iostream>

using namespace std;

int n;
int a[11];
int oper[4];  // add, sub, mul, div
int M = -1000000001;
int m = 1000000001;

void calc(int result, int index) {
    if (index == n) {
        if (result > M)
            M = result;
        if (result < m)
            m = result;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (oper[i] > 0) {
            oper[i]--;
            if (i == 0) {  // add
                calc(result + a[index], index + 1);
            } else if (i == 1) {  // sub
                calc(result - a[index], index + 1);
            } else if (i == 2) {  // mul
                calc(result * a[index], index + 1);
            } else {  // i == 3, div
                calc(result / a[index], index + 1);
            }
            oper[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> oper[0] >> oper[1] >> oper[2] >> oper[3];

    calc(a[0], 1);
    cout << M << '\n';
    cout << m << '\n';

}
