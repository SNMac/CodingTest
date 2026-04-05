#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
int empty_count;
vector<pair<int, int>> empty_coord;  // (y, x)
bool is_completed;

bool isValid(pair<int, int> coord) {  // check if coordinate is valid
    for (int i = 0; i < 9; i++) {
        /* column check */
        if (board[coord.first][i] == board[coord.first][coord.second] && i != coord.second)
            return false;
        /* row check */
        if (board[i][coord.second] == board[coord.first][coord.second] && i != coord.first)
            return false;
    }

    /* 3*3 check */
    int x_check = coord.second / 3;
    int y_check = coord.first / 3;
    for (int i = 3 * y_check; i < 3 * y_check + 3; i++) {
        for (int j = 3 * x_check; j < 3 * x_check + 3; j++) {
            if (board[i][j] == board[coord.first][coord.second] && i != coord.first && j != coord.second)
                return false;
        }
    }
    return true;
}

void sudoku(int cur_index) {
    /* output */
    if (cur_index == empty_count) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
        is_completed = true;
        return;
    }

    /* solving */
    for (int i = 1; i <= 9; i++) {
        board[empty_coord[cur_index].first][empty_coord[cur_index].second] = i;
        if (isValid(empty_coord[cur_index]))
            sudoku(cur_index + 1);
        if (is_completed)
            return;
    }
    board[empty_coord[cur_index].first][empty_coord[cur_index].second] = 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                empty_coord.emplace_back(i, j);
                empty_count++;
            }
        }
    }
    sudoku(0);
}