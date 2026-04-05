#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    int rest = 0;
    count = n / 5;
    rest = n % 5;
    if (count == 0) {
        switch (rest) {
            case 3 :
                count = 1;
                break;
            case 4 :
                count = -1;
                break;
        }
    } else if (count == 1) {
        switch (rest) {
            case 1 :
                count++;
                break;
            case 2 :
                count = -1;
                break;
            case 3 :
                count++;
                break;
            case 4 :
                count += 2;
                break;
        }
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