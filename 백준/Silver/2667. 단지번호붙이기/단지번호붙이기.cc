#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 25;
int map[MAX][MAX];
bool visited[MAX][MAX];

// [0]: 상, [1]: 하, [2]: 좌, [3]: 우
int dRow[] = { -1, 1, 0, 0 }; // Row의 변화량 (위아래)
int dCol[] = { 0, 0, -1, 1 }; // Column의 변화량 (좌우)

int n;
vector<int> result;

int bfs(int startRow, int startCol) {
    queue<pair<int, int>> q;

    q.push({ startRow, startCol });
    visited[startRow][startCol] = true;

    int houseCount = 1;

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextRow = row + dRow[i];
            int nextCol = col + dCol[i];

            if (nextRow < 0 || nextRow > n - 1 || nextCol < 0 || nextCol > n - 1)
                continue;

            if (map[nextRow][nextCol] == 1 && !visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = true;
                q.push({ nextRow, nextCol });
                houseCount++;
            }
        }
    }

    return houseCount;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                int count = bfs(i, j);
                result.push_back(count);
            }
        }
    }

    sort(result.begin(), result.end());

    printf("%zu\n", result.size());
    for (int i = 0; i < result.size(); i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
