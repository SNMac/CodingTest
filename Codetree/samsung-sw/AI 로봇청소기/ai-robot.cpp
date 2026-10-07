#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAP_MAX = 31;
const int ROBOT_MAX = 51;

int map[MAP_MAX][MAP_MAX];
pair<int, int> robots[ROBOT_MAX];
bool hasRobot[MAP_MAX][MAP_MAX];

// [0]: 우, [1]: 하, [2]: 좌, [3]: 상
int dr[] = {0, 1, 0, -1};  // Row의 변화량 (위아래)
int dc[] = {1, 0, -1, 0};  // Column의 변화량 (좌우)

int n, k, l;

bool isOutOfMap(int r, int c) { return (r < 1 || r > n || c < 1 || c > n); }

pair<int, int> moveRobots(int index) {
    int startR = robots[index].first;
    int startC = robots[index].second;

    int dist[MAP_MAX][MAP_MAX];
    fill(dist[0], dist[0] + (MAP_MAX * MAP_MAX), -1);

    queue<pair<int, int>> q;
    q.push({startR, startC});
    dist[startR][startC] = 0;

    vector<pair<int, int>> candidates;
    int minDist = INT_MAX;

    while (!q.empty()) {
        int nowR = q.front().first;
        int nowC = q.front().second;
        q.pop();

        if (dist[nowR][nowC] > minDist) break;

        if (map[nowR][nowC] > 0) {
            minDist = dist[nowR][nowC];
            candidates.push_back({nowR, nowC});
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nextR = nowR + dr[i];
            int nextC = nowC + dc[i];

            if (isOutOfMap(nextR, nextC)) continue;
            if (map[nextR][nextC] == -1) continue;  // 물건이 위치한 격자
            if (hasRobot[nextR][nextC] == true) continue;

            if (dist[nextR][nextC] == -1) {
                dist[nextR][nextC] = dist[nowR][nowC] + 1;
                q.push({nextR, nextC});
            }
        }
    }

    if (candidates.empty()) return {-1, -1};

    sort(candidates.begin(), candidates.end());

    return candidates[0];
}

void clean(int nowR, int nowC) {
    int maxDust = -1;
    int bestDirIndex = -1;

    for (int dirIndex = 0; dirIndex < 4; dirIndex++) {
        int currDustSum = min(20, map[nowR][nowC]);
        int backDirIndex = (dirIndex + 2) % 4;

        for (int i = 0; i < 4; i++) {
            if (i == backDirIndex) continue;

            int nextR = nowR + dr[i];
            int nextC = nowC + dc[i];

            if (isOutOfMap(nextR, nextC)) continue;
            if (map[nextR][nextC] == -1) continue;

            currDustSum += min(20, map[nextR][nextC]);
        }

        if (currDustSum > maxDust) {
            maxDust = currDustSum;
            bestDirIndex = dirIndex;
        }
    }

    if (bestDirIndex != -1) {
        map[nowR][nowC] = max(0, map[nowR][nowC] - 20);

        int backDirIndex = (bestDirIndex + 2) % 4;
        for (int i = 0; i < 4; i++) {
            if (i == backDirIndex) continue;

            int nextR = nowR + dr[i];
            int nextC = nowC + dc[i];

            if (isOutOfMap(nextR, nextC)) continue;
            if (map[nextR][nextC] == -1) continue;

            map[nextR][nextC] = max(0, map[nextR][nextC] - 20);
        }
    }
}

void accumulateDust() {
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (map[r][c] > 0) map[r][c] += 5;
        }
    }
}

void diffuseDust() {
    int tempMap[MAP_MAX][MAP_MAX];
    fill(tempMap[0], tempMap[0] + (MAP_MAX * MAP_MAX), 0);

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (map[r][c] == 0) {
                int surroundingDustSum = 0;

                for (int i = 0; i < 4; i++) {
                    int nextR = r + dr[i];
                    int nextC = c + dc[i];

                    if (isOutOfMap(nextR, nextC)) continue;
                    if (map[nextR][nextC] == -1) continue;

                    if (map[nextR][nextC] > 0) {
                        surroundingDustSum += map[nextR][nextC];
                    }
                }

                tempMap[r][c] = surroundingDustSum / 10;
            }
        }
    }

    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (map[r][c] == 0 && tempMap[r][c] > 0) {
                map[r][c] = tempMap[r][c];
            }
        }
    }
}

void printDustSum() {
    int sum = 0;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            int dust = map[r][c];
            if (dust > 0) sum += dust;
        }
    }

    printf("%d\n", sum);
}

int main() {
    scanf("%d %d %d", &n, &k, &l);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 1; i <= k; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        robots[i] = {r, c};
        hasRobot[r][c] = true;
    }

    for (int time = 1; time <= l; time++) {
        // 1. 청소기 이동
        for (int i = 1; i <= k; i++) {
            int oldR = robots[i].first;
            int oldC = robots[i].second;

            pair<int, int> nextPos = moveRobots(i);

            if (nextPos.first == -1 && nextPos.second == -1) continue;

            int nextR = nextPos.first;
            int nextC = nextPos.second;

            hasRobot[oldR][oldC] = false;
            robots[i] = {nextR, nextC};
            hasRobot[nextR][nextC] = true;
        }

        // 2. 청소
        for (int i = 1; i <= k; i++) {
            clean(robots[i].first, robots[i].second);
        }

        // 3. 먼지 축적
        accumulateDust();

        // 4. 먼지 확산
        diffuseDust();

        // 5. 출력
        printDustSum();
    }

    return 0;
}
