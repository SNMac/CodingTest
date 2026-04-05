#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 4 || n == 7) {
        cout << -1 << endl;
        return 0;
    }
    int count;
    switch (n % 5) {
        case 0 :
            count = n / 5;
            break;

        case 1 :
            count = n / 5 + 1;
            break;

        case 2 :
            count = n / 5 + 2;
            break;

        case 3 :
            count = n / 5 + 1;
            break;

        case 4 :
            count = n / 5 + 2;
            break;
    }
    cout << count << endl;
}