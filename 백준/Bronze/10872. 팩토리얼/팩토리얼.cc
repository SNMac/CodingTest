#include <iostream>

using namespace std;

int factorial(int n) {
    int result = n;
    if (n == 0 || n == 1)
        return 1;
    else {
        result *= factorial(n - 1);
        return result;
    }
}

int main() {
    int n;
    cin >> n;
    cout << factorial(n) << '\n';
}