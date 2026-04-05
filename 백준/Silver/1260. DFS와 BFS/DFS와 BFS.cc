#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_NODE_COUNT = 1001;
vector<int> graph[MAX_NODE_COUNT];
bool visited[MAX_NODE_COUNT];

void dfs(int node) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        printf("%d ", node);

        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    printf("\n");

    fill(visited, visited + MAX_NODE_COUNT, false);

    bfs(v);
    printf("\n");

    return 0;
}
