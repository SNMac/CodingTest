#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    if (x > w / 2 && y > h / 2) {
        if (w - x < h - y)
            cout << w - x << '\n';
        else
            cout << h - y << '\n';
    } else if (x > w / 2 && y <= h / 2) {
        if (w - x < y)
            cout << w - x << '\n';
        else
            cout << y << '\n';
    } else if (x <= w / 2 && y > h / 2) {
        if (x < h - y)
            cout << x << '\n';
        else
            cout << h - y << '\n';
    } else {
        if (x < y)
            cout << x << '\n';
        else
            cout << y << '\n';
    }
}