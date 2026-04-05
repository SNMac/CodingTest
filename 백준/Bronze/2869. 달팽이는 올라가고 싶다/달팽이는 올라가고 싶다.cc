#include <iostream>

using namespace std;

int main() {
    int a, b, v;
    cin >> a >> b >> v;

    int days = (v - a) / (a - b);
    if ((v - a) % (a - b) != 0)
        days++;
    if ((a - b) * days + a >= v)
        days++;
    cout << days << endl;
}