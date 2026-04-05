#include <iostream>

#define PI 3.14159265358979

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r;
    cin >> r;
    double euclid = (double)(r * r) * PI;
    int taxi = (4 * r * r) >> 1;
    cout << fixed;
    cout.precision(6);
    cout << euclid << '\n' << (double)taxi << '\n';
}