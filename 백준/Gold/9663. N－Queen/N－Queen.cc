#include <iostream>

using namespace std;

int n, ans;
int col[15];  // col[row] = y, (row, y)

void dfs(int row) {
    if (row == n + 1) {
        ans++;
        return;
    }

    for (int cur_col = 1; cur_col <= n; cur_col++) {
        if (col[row] == 0) {  // coordinate is available
            bool valid = true;
            for (int prev_row = 1; prev_row < row; prev_row++) {  // check
                if (col[prev_row] == cur_col || abs(prev_row - row) == abs(col[prev_row] - cur_col)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                col[row] = cur_col;
                dfs(row + 1);
                col[row] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dfs(1);
    cout << ans << '\n';
}