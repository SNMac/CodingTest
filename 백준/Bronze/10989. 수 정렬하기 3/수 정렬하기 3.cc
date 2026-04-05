#include <iostream>

#define MAX 10001

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    int count[MAX];
    fill_n(count, MAX, 0);
    int max = 1;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        count[input]++;
        if (input > max)
            max = input;
    }

    for (int i = 1; i <= max; i++) {
        while(count[i]) {
            cout << i << '\n';
            count[i]--;
        }
    }
}