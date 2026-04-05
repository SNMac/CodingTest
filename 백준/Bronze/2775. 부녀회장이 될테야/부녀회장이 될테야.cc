#include <iostream>

using namespace std;

int apart(int k, int n) {
    if (k == 0)
        return n;
    else {
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            ret += apart(k - 1, i);
        }
        return ret;
    }
}

int main() {
    int t, k, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> k;
        cin >> n;
        cout << apart(k, n) << endl;
    }
}