#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ans;
    cin >> n >> m;

    /* n! */
    int top = n;
    int top_five = 0;
    while(top >= 5) {
        top_five += top / 5;
        top /= 5;
    }
    top = n;
    int top_two = 0;
    while(top >= 2) {
        top_two += top / 2;
        top /= 2;
    }

    /* m! */
    int bottom_M = m;
    int bottom_five = 0;
    while(bottom_M >= 5) {
        bottom_five += bottom_M / 5;
        bottom_M /= 5;
    }
    bottom_M = m;
    int bottom_two = 0;
    while(bottom_M >= 2) {
        bottom_two += bottom_M / 2;
        bottom_M /= 2;
    }

    /* (n - m)! */
    int bottom_N_M = n - m;
    while(bottom_N_M >= 5) {
        bottom_five += bottom_N_M / 5;
        bottom_N_M /= 5;
    }
    bottom_N_M = n - m;
    while(bottom_N_M >= 2) {
        bottom_two += bottom_N_M / 2;
        bottom_N_M /= 2;
    }
    top_five -= bottom_five;
    top_two -= bottom_two;
    ans = min(top_five, top_two);

    cout << ans << '\n';
}