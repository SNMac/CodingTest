#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    double *arr = new double[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (max < arr[i])
            max = arr[i];
    }

    for (int i = 0; i < n; i++)
        arr[i] = arr[i] / max * 100;

    double avg = 0;
    for (int i = 0; i < n; i++)
        avg += arr[i];
    avg /= n;

    cout << fixed;
    cout.precision(2);
    cout << avg << endl;
    delete[] arr;
}