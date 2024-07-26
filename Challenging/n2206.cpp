#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
#define ALL(x) x.begin(), x.end()
#define FOR(y, x) for (int y = 0; y < (x); y++)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr int sz = 1001;
constexpr int INF = 0x7fffffff;
int N, M;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
vector<vector<bool>> dised;
vector<vector<bool>> copydis;

int bfs(int r, int c) {
    vector<vector<int>> distance(N, vector<int>(M, INF));
    queue<pii> q;
    dised[r][c] = true;
    distance[r][c] = 0;
    q.emplace(r, c);
    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = cr + dr[k];
            int nc = cc + dc[k];
            if (0 <= nr && nr < N && 0 <= nc && nc < M && dised[nr][nc] == false) {
                dised[nr][nc] = true;
                distance[nr][nc] = distance[cr][cc] + 1;
                q.emplace(nr, nc);
                if (nr == N - 1 && nc == M - 1) {
                    return distance[nr][nc] + 1;
                }
            }
        }
    }
    return INF;
}

int bfsAll() {
    dised.assign(copydis.begin(), copydis.end());
    int Answer = bfs(0, 0);
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (copydis[r][c] == true) {
                dised.assign(copydis.begin(), copydis.end());
                dised[r][c] = false;
                Answer = min(Answer, bfs(0, 0));
            }
        }
    }
    return Answer == INF ? -1 : Answer;
}

int solve() {
    int Answer;
    char ch;
    cin >> N >> M;
    copydis.resize(N, vector<bool>(M, false));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> ch;
            copydis[r][c] = (ch=='1');
        }
    }
    Answer = bfsAll();
    return Answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cout << solve();
    return 0;
}