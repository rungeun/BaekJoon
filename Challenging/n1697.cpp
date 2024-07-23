#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;

vector<vector<int>> adj;

// start에서 시작해 end에 도달하는 최단 거리를 찾는 BFS 함수
int bfs(int start, int end) {
    vector<bool> discovered(adj.size(), false);
    vector<int> distance(adj.size(), 0);  // 각 정점까지의 거리를 저장
    queue<int> q;
    discovered[start] = true;
    q.push(start);

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        if (here == end) return distance[here];  // 목적지에 도달하면 거리 반환

        for (int there : adj[here]) {
            if (!discovered[there]) {
                q.push(there);
                discovered[there] = true;
                distance[there] = distance[here] + 1;  // 거리 갱신
            }
        }
    }

    return -1;
}

int solve() {
    int s, e;
    cin >> s >> e;
    if (s >= e) {
        return s - e;
    }
    int GraphSize = e * 2 + 1;

    adj.resize(GraphSize);

    for (int i = 0; i < GraphSize; ++i) {
        if (i + 1 < GraphSize) {
            adj[i].push_back(i + 1);
        }
        if (i - 1 >= 0) {
            adj[i].push_back(i - 1);
        }
        if (i * 2 < GraphSize) {
            adj[i].push_back(i * 2);
        }
    }

    return bfs(s, e);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << solve();
    return 0;
}
