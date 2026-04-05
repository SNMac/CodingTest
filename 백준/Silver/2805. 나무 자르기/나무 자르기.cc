#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int* tree = new int[n];
    long long min = 0, max = 1000000000, midCut;
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
        if (tree[i] < min)
            min = tree[i];
        if (tree[i] > max)
            max = tree[i];
    }

    long long ans = 0;
    while(min <= max) {
        long long total = 0;
        midCut = (min + max) / 2;
        for (int i = 0; i < n; i++) {
            if (tree[i] > midCut)
                total += tree[i] - midCut;
        }
        if (total < m) {  // need more trees, midCut needs to be lower
            max = midCut - 1;
        } else if (total > m) {  // need fewer trees, midCut needs to be higher
            min = midCut + 1;
            if (ans < midCut)
                ans = midCut;
        } else {
            ans = midCut;
            break;
        }
    }
    cout << ans << '\n';
    delete[] tree;
}