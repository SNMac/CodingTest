#include <iostream>

#define POW(n) (n) * (n)

using namespace std;

int x1, y1, r1, x2, y2, r2;

int position() {
    int distPow = POW(x2 - x1) + POW(y2 - y1);
    if (x1 == x2 && y1 == y2) {
        if (r1 == r2)
            return -1;
        else
            return 0;
    } else if (distPow > POW(r1 + r2)) {
        return 0;
    } else if (distPow == POW(r1 + r2)) {
        return 1;
    } else {  // distPow < POW(r1 + r2)
        if (POW(r2 - r1) > distPow)
            return 0;
        else if (POW(r2 - r1) == distPow)
            return 1;
        else  // POW(r2 - r1) < distPow
            return 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        cout << position() << '\n';
    }
}