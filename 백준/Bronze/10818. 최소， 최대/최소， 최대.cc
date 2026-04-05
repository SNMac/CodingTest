#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int l, h;
    l = arr[0];
    h = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > h)
            h = arr[i];
        else if (arr[i] < l)
            l = arr[i];
    }
    cout << l << " " << h;
}