#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        int minN, MAXN;
        if (a > b) {
            MAXN = a;
            minN = b;
        } else {
            MAXN = b;
            minN = a;
        }
        int multiple = minN;
        int m = 1;
        while(multiple < MAXN)
            multiple = minN * m++;
        while(true) {
            if (!(multiple % MAXN)) {
                cout << multiple << '\n';
                break;
            } else {
                multiple = minN * m++;
            }
        }
    }
}