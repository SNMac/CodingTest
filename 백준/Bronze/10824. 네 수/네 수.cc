#include <iostream>
#include <string>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

string a, b, c, d;
unsigned long long x, y;

int main() {
    FAST_IO

    cin >> a >> b >> c >> d;

    a += b; c += d;
    x = stoull(a); y = stoull(c);

    cout << x + y << '\n';
}
