#include <iostream>
#include <string>

using namespace std;

char** star;

void countingStar(int x, int y, int n) {
    if ((x / n) % 3 == 1 && (y / n) % 3 == 1) {
        star[y][x] = ' ';
    } else {
        if (n == 1) {
            star[y][x] = '*';
        } else {
            countingStar(x, y, n / 3);
        }
    }
}

int main() {
    int n;
    cin >> n;

    star = new char*[n];
    for (int i = 0; i < n; i++) {
        star[i] = new char[n];
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            countingStar(x, y, n);
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << star[y][x];
        }
        cout << '\n';
    }


    for (int i = 0; i < n; i++) {
        delete[] star[i];
    }
    delete[] star;
}