#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;

vector<vector<int>> vec;
vector<bool> vied;

void dfs(int here) {
    cout << here << ' ';
    vied[here] = true;
    for (int _ = 0; _ < vec[here].size(); _++) {
        int there = vec[here][_];
        if (!vied[there]) dfs(there);
    }
}

vector<int> bfs(int start) {
    vector<bool> dised(vec.size(), false);
    vector<int> order;
    queue<int> q;
    dised[start] = true;
    q.push(start);
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        order.push_back(here);
        for (int _ = 0; _ < vec[here].size(); _++) {
            int there = vec[here][_];
            if (!dised[there]) {
                q.push(there);
                dised[there] = true;
            }
        }
    }
    return order;
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M, V;
    int a, b;
    cin >> N >> M >> V;
    vec.resize(N + 1);
    vied.resize(N + 1, false);

    for (int _ = 0; _ < M; _++) {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 1; i < N+1; i++) {  // O(NlgM)
        if (!vec[i].empty()) {
            sort(vec[i].begin(), vec[i].end());  // i행에 저장된 열들을 정렬하고 싶음
        }
    }

    dfs(V);
    cout << '\n';
    vector<int> order = bfs(V);
    for (int _ = 0; _ < order.size(); _++) {
        cout << order[_] << ' ';
    }
    return 0;
}