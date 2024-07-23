#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr int sz = 1 << 17;
constexpr int INF = INT_MAX;

int N, M;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
// 길=0(미방문), 벽=1(방문), 사람=2(미방문)
vector<vector<int>> dised;

int bfs(int r, int c) {
    int count = 0;
    queue<pii> q;
    dised[r][c] = 1;
    q.emplace(r, c);
    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = cr + dr[k];
            int nc = cc + dc[k];

            if (0 <= nr && nr < N && 0 <= nc && nc < M && dised[nr][nc] != 1) {
                if (dised[nr][nc] == 2) {
                    ++count;
                }
                dised[nr][nc] = 1;
                q.emplace(nr, nc);
            }
        }
    }
    return count;
}

int solve() {
    int Answer = 0;

    int starti, startj;
    cin >> N >> M;
    dised.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x;
            cin >> x;
            if (x == 'X') {
                dised[i][j] = 1;
            } else if (x == 'I') {
                starti = i;
                startj = j;
            } else if (x == 'P') {
                dised[i][j] = 2;
            }
        }
    }

    Answer = bfs(starti, startj);

    return Answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int An = solve();
    if (An == 0) {
        cout << "TT";
    } else {
        cout << An;
    }
    return 0;
}