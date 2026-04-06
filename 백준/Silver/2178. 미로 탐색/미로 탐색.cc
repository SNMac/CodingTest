#include <iostream>
#include <queue>

using namespace std;

const int MAX = 101;
int maze[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int n, m;

// [0]: 상, [1]: 하, [2]: 좌, [3]: 우
int dRow[] = {-1, 1, 0, 0};     // Row(행)의 변화량 (위아래)
int dColumn[] = {0, 0, -1, 1};  // Column(열)의 변화량 (좌우)

void bfs(int startRow, int startColumn) {
    queue<pair<int, int>> q;

    q.push({startRow, startColumn});
    visited[startRow][startColumn] = true;
    dist[startRow][startColumn] = 1;

    while (!q.empty()) {
        int nowRow = q.front().first;
        int nowColumn = q.front().second;
        q.pop();

        // 현재 위치에서 상하좌우 4방향 모두 탐색
        for (int i = 0; i < 4; i++) {
            int nextRow = nowRow + dRow[i];
            int nextColumn = nowColumn + dColumn[i];

            if (nextRow < 1 || nextRow > n || nextColumn < 1 || nextColumn > m) continue;

            if (maze[nextRow][nextColumn] == 0 || visited[nextRow][nextColumn] == true) continue;

            visited[nextRow][nextColumn] = true;
            dist[nextRow][nextColumn] = dist[nowRow][nowColumn] + 1;
            q.push({nextRow, nextColumn});
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    bfs(1, 1);

    printf("%d\n", dist[n][m]);
}
