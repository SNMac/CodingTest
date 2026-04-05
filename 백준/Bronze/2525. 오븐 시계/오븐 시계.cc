#include <iostream>

using namespace std;

int main() {
    int h, m, time;
    cin >> h >> m;
    cin.ignore();
    cin >> time;
    m += time;
    while (m >= 60) {
        m -= 60;
        h += 1;
        if (h >= 24)
            h = 0;
    }
    cout << h << " " << m << endl;
}