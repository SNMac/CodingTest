#include <iostream>

using namespace std;

int n, m;
bool isUsed[9];
int arr[8];

void dfs(int cur_digit) {
    if (cur_digit == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!isUsed[i]) {
            isUsed[i] = true;
            arr[cur_digit] = i;
            dfs(cur_digit + 1);
            isUsed[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    dfs(0);
}