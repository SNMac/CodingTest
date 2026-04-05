#include <iostream>

using namespace std;

int count = 0;

int MenOfPassion(const int A[], int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        count++;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int arr[n / 2];
    int result = MenOfPassion(arr, n);
    cout << count << '\n';
    cout << 1 << '\n';
}
