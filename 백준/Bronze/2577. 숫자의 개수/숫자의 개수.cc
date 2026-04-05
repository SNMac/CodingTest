#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    a = a * b * c;

    int* res = new int[10];
    bool start = false;
    for (int i = 9; i >= 0; i--) {
        if (a / (int)pow(10, i) != 0)
            start = true;
        if (start)
            res[a / (int)pow(10, i)]++;
        a %= (int)pow(10, i);
    }

    for (int i = 0; i < 10; i++) {
        cout << res[i] << endl;
    }
    delete[] res;
}