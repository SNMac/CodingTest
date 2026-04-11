#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAP_MAX = 51;
const int BOX_MAX = 101;

struct Box {
    int r = 1;  // 행
    int c;      // 열
    int w;      // 너비
    int h;      // 높이
    int k;      // 택배 번호
};

int map[MAP_MAX][MAP_MAX];
vector<Box> boxes;

int n, m;

int calcBottomRow(int row, int height) {
    return row + height - 1;
}
int calcRightColumn(int col, int width) {
    return col + width - 1;
}
bool compareBox(pair<int, Box> a, pair<int, Box> b) {
    return a.second.k < b.second.k;
}

void setBox(int index) {
    Box box = boxes[index];

    // 택배 원래 위치 초기화
    for (int r = box.r; r <= calcBottomRow(box.r, box.h); r++) {
        for (int c = box.c; c <= calcRightColumn(box.c, box.w); c++) {
            map[r][c] = 0;
        }
    }

    // 중력 적용
    int nextBottomR = calcBottomRow(box.r, box.h) + 1;
    while (nextBottomR <= n) {
        bool canDrop = true;

        for (int c = box.c; c <= calcRightColumn(box.c, box.w); c++) {
            if (map[nextBottomR][c] != 0) {
                canDrop = false;
                break;
            }
        }

        if (!canDrop) break;

        box.r += 1;
        nextBottomR = calcBottomRow(box.r, box.h) + 1;
    }

    // 택배 위치 확정
    for (int r = box.r; r <= calcBottomRow(box.r, box.h); r++) {
        for (int c = box.c; c <= calcRightColumn(box.c, box.w); c++) {
            map[r][c] = box.k;
        }
    }

    boxes[index] = box;
}

void unloadBox(int index, Box box) {
    int topR = box.r;
    int bottomR = calcBottomRow(box.r, box.h);
    int leftC = box.c;
    int rightC = calcRightColumn(box.c, box.w);
    for (int r = topR; r <= bottomR; r++) {
        for (int c = leftC; c <= rightC; c++) {
            map[r][c] = 0;
        }
    }

    boxes.erase(boxes.begin() + index);
}

int unloadLeft() {
    vector<pair<int, Box>> candidates;

    // 모든 택배를 대상으로 좌측에 박스가 없는 택배 추출
    for (int i = 0; i < boxes.size(); i++) {
        Box box = boxes[i];

        // 좌측에 박스가 없는지 확인
        int topR = box.r;
        int bottomR = calcBottomRow(box.r, box.h);
        bool canUnloaded = true;
        for (int c = 1; c < box.c; c++) {
            if (map[topR][c] != 0 || map[bottomR][c] != 0) {
                canUnloaded = false;
                break;
            }
        }
        if (!canUnloaded) continue;

        candidates.push_back({i, box});
    }

    // 택배 번호가 작은 순서대로 정렬
    sort(candidates.begin(), candidates.end(), compareBox);

    // 택배 번호가 가장 작은 택배 하차
    unloadBox(candidates.front().first, candidates.front().second);

    // 택배 위치 조정(중력 적용)
    for (int i = 0; i < boxes.size(); i++) {
        setBox(i);
    }

    return candidates.front().second.k;
}

int unloadRight() {
    vector<pair<int, Box>> candidates;

    // 모든 택배를 대상으로 우측에 박스가 없는 택배 추출
    for (int i = 0; i < boxes.size(); i++) {
        Box box = boxes[i];

        // 우측에 박스가 없는지 확인
        int topR = box.r;
        int bottomR = calcBottomRow(box.r, box.h);
        bool canUnloaded = true;
        for (int c = calcRightColumn(box.c, box.w) + 1; c <= n; c++) {
            if (map[topR][c] != 0 || map[bottomR][c] != 0) {
                canUnloaded = false;
                break;
            }
        }
        if (!canUnloaded) continue;

        candidates.push_back({i, box});
    }

    // 택배 번호가 작은 순서대로 정렬
    sort(candidates.begin(), candidates.end(), compareBox);

    // 택배 번호가 가장 작은 택배 하차
    unloadBox(candidates.front().first, candidates.front().second);

    // 택배 위치 조정(중력 적용)
    for (int i = 0; i < boxes.size(); i++) {
        setBox(i);
    }

    return candidates.front().second.k;
}

int main() {
    scanf("%d %d", &n, &m);

    // 1. 택배 투입
    for (int i = 0; i < m; i++) {
        int k, h, w, c;
        Box box;
        scanf("%d %d %d %d", &box.k, &box.h, &box.w, &box.c);
        boxes.push_back(box);
        setBox(i);
    }

    while (!boxes.empty()) {
        // 2. 택배 하차 (좌측)
        printf("%d\n", unloadLeft());

        // 3. 택배 하차 (우측)
        printf("%d\n", unloadRight());
    }

    return 0;
}
