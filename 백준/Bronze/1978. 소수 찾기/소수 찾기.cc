#include <iostream>

using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 1; j <= arr[i]; j++) {
            if (arr[i] % j == 0)
                count++;
            if (count > 2)
                break;
        }
        if (count == 2)
            result++;
    }

    cout << result << endl;
    delete[] arr;
}