#include <iostream>

using namespace std;

int main() {
    int a , b;
    cin >> a >> b;
    int l1, l2, l3, l4;
    l1 = a * (b % 10);
    l2 = a * ((b % 100) / 10);
    l3 = a * (b / 100);
    l4 = l1 + l2 * 10 + l3 * 100;
    cout << l1 << endl;
    cout << l2 << endl;
    cout << l3 << endl;
    cout << l4 << endl;
}