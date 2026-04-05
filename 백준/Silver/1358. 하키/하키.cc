#include <iostream>

#define POW(n) (n) * (n)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, h, x, y, p;
    cin >> w >> h >> x >> y >> p;
    int r, lcx, lcy, rcx, rcy;
    r = h / 2;
    lcx = x; lcy = y + r; rcx = x + w; rcy = y + r;
    int count = 0;
    for (int i = 0; i < p; i++) {
        int px, py;
        cin >> px >> py;
        if (px >= x && px <= x + w && py >= y && py <= y + h) {
            count++;
            continue;
        }
        int lcDist = POW(px - lcx) + POW(py - lcy);
        int rcDist = POW(px - rcx) + POW(py - rcy);
        if (lcDist <= POW(r) || rcDist <= POW(r))
            count++;
    }
    cout << count << '\n';
}