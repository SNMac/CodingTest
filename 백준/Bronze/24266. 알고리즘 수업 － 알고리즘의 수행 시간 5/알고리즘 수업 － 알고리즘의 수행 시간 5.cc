#include <iostream>

using namespace std;

unsigned long long count = 0;

void MenOfPassion(unsigned long long n) {
    count = n * n * n;
}

int main() {
    unsigned long long n;
    cin >> n;
    MenOfPassion(n);
    cout << count << '\n';
    cout << 3 << '\n';
}
