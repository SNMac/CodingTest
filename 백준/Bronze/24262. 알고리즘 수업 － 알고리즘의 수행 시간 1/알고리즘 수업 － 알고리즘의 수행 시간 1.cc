#include <iostream>

using namespace std;

int MenOfPassion(int A[], int n) {
    int i = n / 2;
    return A[i];
}

int main() {
    int n;
    cin >> n;
    int arr[n / 2];
    int result = MenOfPassion(arr, n);
    cout << 1 << '\n';
    cout << 0 << '\n';
}
