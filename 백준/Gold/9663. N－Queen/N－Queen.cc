#include <iostream>

using namespace std;

int n, ans;
int col_arr[15];  // col_arr[col] = row, (col, row)
int up_diagonal[30];
int down_diagonal[30];

void dfs(int row) {
    if (row == n + 1) {
        ans++;
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (col_arr[col] || up_diagonal[col + row] || down_diagonal[col - row + n - 1])
            continue;
        
        col_arr[col] = row;
        up_diagonal[col + row] = 1;
        down_diagonal[col - row + n - 1] = 1;
        dfs(row + 1);
        col_arr[col] = 0;
        up_diagonal[col + row] = 0;
        down_diagonal[col - row + n - 1] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dfs(1);
    cout << ans << '\n';
}