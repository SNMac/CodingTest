#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int distW = w - x;
    int distH = h - y;
    int arr[] = {x, y, distW, distH};
    cout << *min_element(arr, arr + 4) << '\n';
}