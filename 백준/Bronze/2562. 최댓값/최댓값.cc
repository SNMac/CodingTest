#include <iostream>

using namespace std;

int main() {
    int arr[9];
    for (int i = 0; i < 9; i++)
        cin >> arr[i];
    int h, num;
    h = arr[0];
    num = 0;
    for (int i = 0; i < 9; i++) {
        if (arr[i] > h) {
            h = arr[i];
            num = i;
        }
    }
    cout << h << "\n" << num + 1 << endl;
}