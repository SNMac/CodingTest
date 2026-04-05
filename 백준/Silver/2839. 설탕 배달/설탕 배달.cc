#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int count = n / 5;
    int rest = n % 5;
    if (count < 2) {
        if (n == 4 || n == 7)
            count = -1;
        else if (n == 3 || n == 6 || n == 9)
            count = n / 3;
        else if (n == 8)
            count++;
    } else {
        switch (rest) {
            case 1 :
                count++;
                break;
            case 2 :
                count += 2;
                break;
            case 3 :
                count++;
                break;
            case 4 :
                count += 2;
                break;
        }
    }
    cout << count << endl;
}