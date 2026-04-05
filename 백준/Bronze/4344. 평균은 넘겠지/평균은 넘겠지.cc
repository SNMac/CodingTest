#include <iostream>

using namespace std;

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int n;
        cin >> n;
        int* arr = new int [n];
        for (int a = 0; a < n; a++)
            cin >> arr[a];

        double avg = 0;
        for (int a = 0; a < n; a++)
            avg += arr[a];
        avg /= (double)n;

        int over = 0;
        for (int a = 0; a < n; a++) {
            if (arr[a] > avg)
                over++;
        }
        double res = (double)over / (double)n * 100;

        cout << fixed;
        cout.precision(3);
        cout << res << "%\n";
        delete[] arr;
    }
}