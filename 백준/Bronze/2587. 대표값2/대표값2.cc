#include <iostream>

using namespace std;

int main() {
    int arr[5], avg = 0;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        avg += arr[i];
    }
    avg /= 5;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << avg << '\n' << arr[2] << '\n';
}