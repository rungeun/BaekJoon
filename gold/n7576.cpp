#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#if !(defined ONLINE_JUDGE || defined CODE_GROUND)
#define TEST(X, Y) cerr << (X) << ": " << (Y) << '\n'
#else
#define TEST(x, Y)
#endif
#define ALL(x) x.begin(), x.end()
#define FOR(y, x) for (int(y) = 0; (y) < (x); (y)++)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr int sz = 1 << 17;
constexpr int INF = 0x7fffffff;
int N, M;
int maxCnt = 0;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};
vector<vector<int>> dis;
queue<pii> qu;
int AllCnt = 0;
void bfs(int r, int c) {
    FOR(k, 4) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (0 <= nr && nr < N && 0 <= nc && nc < M && dis[nr][nc] == 0) {
            qu.emplace(nr, nc);
            dis[nr][nc] = dis[r][c] + 1;
            AllCnt++;
            maxCnt = max(maxCnt, dis[r][c]);
        }
    }
}

/*
//[x]: 최초 위치(1) 큐에 넣음
//[x]: 큐에 있는 원소들 bfs
//[x]: bfs돌리면서 다음 위치 큐에 넣음
//[x]: 반복
*/

int solve() {
    int Answer = 0;
    int x;
    cin >> M >> N;
    dis.assign(N, vector<int>(M, 0));
    FOR(i, N) FOR(j, M) {
        cin >> x;
        dis[i][j] = x;
        if (x == 1) {
            qu.emplace(i, j);
        }
        if (x == 1 || x == -1) {
            AllCnt++;
        }
    }

    while (!qu.empty()) {
        auto [cr, cc] = qu.front();
        qu.pop();
        bfs(cr, cc);
    }

#ifndef ONLINE_JUDGE
    FOR(r, N) {
        FOR(c, M) { cerr << dis[r][c] << ' '; }
        cerr << '\n';
    }

#endif

    Answer = maxCnt;
    TEST("1", AllCnt);
    if (AllCnt != N * M) Answer = -1;
    return Answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cout << solve() << '\n';
    return 0;
}