#include <iostream>

using namespace std;

unsigned long long count = 0;

void MenOfPassion(unsigned long long n) {
    count = n - 1;
    for (int i = 2; i <= n; i++)
        count += n - i;
}

int main() {
    unsigned long long n;
    cin >> n;
    MenOfPassion(n);
    cout << count << '\n';
    cout << 2 << '\n';
}
