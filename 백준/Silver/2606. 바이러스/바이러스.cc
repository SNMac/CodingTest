#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;
vector<int> graph[MAX];
bool visited[MAX];

int comCount, connectedCount;
int result = -1;

void dfs(int nowCom) {
    result++;
    visited[nowCom] = true;

    for (int i = 0; i < graph[nowCom].size(); i++) {
        int nextCom = graph[nowCom][i];
        if (!visited[nextCom]) {
            dfs(nextCom);
        }
    }
}

int main() {
    scanf("%d", &comCount);
    scanf("%d", &connectedCount);

    for (int i = 0; i < connectedCount; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    printf("%d\n", result);

    return 0;
}
