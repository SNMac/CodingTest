#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    int* factor = new int[k];
    for (int i = 0; i < k; i++)
        cin >> factor[i];

    sort(factor, factor + k);
    cout << factor[0] * factor[k - 1] << '\n';
    delete[] factor;
}