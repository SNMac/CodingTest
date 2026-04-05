#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    while(true) {
        cin >> a >> b;
        if (!(a | b))
            break;

        if (!(b % a))
            cout << "factor\n";
        else if (!(a % b))
            cout << "multiple\n";
        else
            cout << "neither\n";
    }
}