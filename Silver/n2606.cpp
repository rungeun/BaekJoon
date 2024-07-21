#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
int Answer = 0;
vector<vector<int>> vec;
vector<bool> vi;

void dfs(int here) {
    vi[here] = true;
    for (int i = 0; i < vec[here].size(); ++i) {
        int there = vec[here][i];
        if (!vi[there]) dfs(there);
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    int s, e;
    cin >> N >> M;
    vec.resize(N + 1);
    for (int _ = 0; _ < M; _++) {
        cin >> s >> e;
        vec[s].push_back(e);
        vec[e].push_back(s);
    }
    vi = vector<bool>(N + 1, false);
    dfs(1);
    for (int _ = 2; _ < N + 1; _++) {
        if (vi[_]) {
            Answer++;
        }
    }
    cout << Answer;
    return 0;
}