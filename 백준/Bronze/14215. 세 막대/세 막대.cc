#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3, compare);

    while (true) {
        if (arr[0] < (arr[1] + arr[2])) {
            cout << arr[0] + arr[1] + arr[2] << '\n';
            break;
        } else {
            arr[0]--;
        }
    }
}
