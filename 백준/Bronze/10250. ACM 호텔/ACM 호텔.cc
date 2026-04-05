#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int t, h, w, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> h >> w >> n;
        int floor = n % h;
        if (floor == 0)
            floor = h;
        int room = n / h + 1;
        if (floor == h)
            room--;
        cout << floor << setfill('0') << setw(2) << room << endl;
    }
}