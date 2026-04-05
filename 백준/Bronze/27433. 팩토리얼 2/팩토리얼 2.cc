#include <iostream>

using namespace std;

unsigned long long fact(int n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main() {
    int N;
    cin >> N;
    cout << fact(N) << '\n';
}
