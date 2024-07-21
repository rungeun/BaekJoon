/*
BFS
*/
#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
// 그래프의 인접 리스트 표현
vector<vector<int>> adj;
// start에서 시작해 그래프를 너비 우선 탑색하고자 각 정점의 방문 순서를 반환한다.
vector<int> bfs(int start) {
    // 각 정점의 방문 여부
    vector<bool> discovered(adj.size(), false);
    // 방문할 정점 목록을 유지하는 큐
    queue<int> q;
    // 정점의 방문 순서
    vector<int> order;
    discovered[start] = true;
    q.push(start);
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        // here에 방문한다.
        order.push_back(here);
        // 모든 인접한 정점을 검사한다.
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i];
            // 처음 보는 정점이면 방문 목록에 집어 넣는다.
            if (!discovered[there]) {
                q.push(there);
                discovered[there] = true;
            }
        }
    }
    return order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; // N: 정점의 수, M: 간선의 수
    cin >> N >> M;

    adj.resize(N + 1); // 정점 번호가 1부터 시작한다고 가정 (0은 사용하지 않음)

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // 무방향 그래프인 경우, 단방향이면 이 줄 제거
    }

    int start = 1; // BFS를 시작할 정점 (예제에서는 1번 정점)
    vector<int> order = bfs(start);

    // BFS 방문 순서 출력
    for (int i = 0; i < order.size(); ++i) {
        cout << order[i] << " ";
    }
    cout << '\n';

    return 0;
}