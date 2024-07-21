/*
사이클 없는 방향 그래프 : DAG
- 희소 그래프 (E가 훨씬 적은 V^2): 인접 리스트 구현이 유리, 연결되어 있는 간선'들'을 찾기 좋음
- 밀집 그래프 (E가 거의 비례 V^2): 인접 행렬 구현이 유리, 간선이 연결되어 있는지 O(1)만에 확인 가능

그래프 탐색(관광)
DFS
- 모든 경로를 탐색해야 할 때
- 백트래킹이 필요한 경우
- 그래프의 연결 요소를 찾을 때
- 사이클을 찾을 때
- 강한 연결 요소(SCC)를 찾을 때
BFS
- 최단 경로를 찾을 때
- 최단 거리 계산
- 레벨 순회
- 그래프의 연결 요소를 찾을 때
*/
#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
// 그래프의 인접 리스트 표현
vector<vector<int>> adj;
// 각 정점을 방문했는지 여부를 나타낸다.
vector<bool> visited;
// 깊이 우선 탐색
void dfs(int here) {
    cout << "DFS visits" << here << '\n';
    visited[here] = true;
    // 모든 인접 정점을 순회하면서
    for (int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i];
        // 아직 방문한 적 없다면 방문한다.
        if (!visited[there]) dfs(there);
    }
}

void dfsAll() {
    // visited를 모두 false로 초기화
    visited = vector<bool>(adj.size(), false);
    // 모든 정점을 순회하면서, 아직 방문한 적 없다면 방문한다.
    for (int i = 0; i < adj.size(); ++i) {  // dfsAll
        if (!visited[i]) dfs(i);
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    dfsAll();
    return 0;
}
