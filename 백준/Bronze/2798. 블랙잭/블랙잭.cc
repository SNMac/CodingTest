#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, m;
    cin >> n >> m;
    int* card = new int[n];
    for (int i = 0; i < n; i++)
        cin >> card[i];
    sort(card, card + n, cmp);

    int temp, sum = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                temp = card[i] + card[j] + card[k];
                if (temp <= m && temp > sum)
                    sum = temp;
            }
        }
    }

    cout << sum << '\n';
    delete[] card;
}