#include <iostream>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    cin.ignore();
    int a, b;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        cin.ignore();
        cout << a + b << "\n";
    }
}