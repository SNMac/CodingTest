#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int edge = 4;
    int sqr = 1;
    int dot = 4;
    for (int i = 1; i <= n; i++) {
        dot += edge + sqr;
        edge = edge * 2 + sqr * 4;
        sqr *= 4;
    }
    cout << dot << '\n';
}
