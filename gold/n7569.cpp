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
int N, M, H;
int maxCnt = 0;
int dr[6] = {0, 0, 0, 0, -1, 1};
int dc[6] = {0, 0, -1, 1, 0, 0};
int dh[6] = {-1, 1, 0, 0, 0, 0};
// 다운 , 업 , 좌, 우 ,하, 상
int dis[101][101][101];
//vector<vector<vector<int>>> dis;
queue<tuple<int, int, int>> qu;
int AllCnt = 0;
void bfs(int r, int c, int h) {
    FOR(k, 6) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        int nh = h + dh[k];
        if (0 <= nr && nr < N && 0 <= nc && nc < M && 0 <= nh && nh < H && dis[nr][nc][nh] == 0) {
            qu.emplace(nr, nc, nh);
            dis[nr][nc][nh] = dis[r][c][h] + 1;
            AllCnt++;
            maxCnt = max(maxCnt, dis[r][c][h]);
        }
    }
}

/*
(전부 -1 해주면 됨)
5 4 3 4 5
4 3 2 3 4
5 4 3 4 5

4 3 2 3 4
3 2 1 2 3
4 3 2 3 4

-1 -1
-1 -1

 1 -1
 0  0

-1  0
-1  0
->
-1 -1
-1 -1

 1 -1
 2  3

-1  5
-1  4


*/
int solve() {
    int Answer = 0;
    int x;
    bool zeroCnt = false;
    cin >> M >> N >> H;
    //dis.assign(N, vector<vector<int>>(M, vector<int>(H, 0)));

    FOR(k, H) FOR(i, N) FOR(j, M) {
        cin >> x;
        dis[i][j][k] = x;
        if (x == 1) {
            qu.emplace(i, j, k);
        }
        if (x == 1 || x == -1) {
            AllCnt++;
        }
        if (x == 0) {
            zeroCnt = true;
        }
    }
    if (!zeroCnt) return 0;
    while (!qu.empty()) {
        auto [cr, cc, ch] = qu.front();
        qu.pop();
        bfs(cr, cc, ch);
    }

    Answer = maxCnt;
    TEST("1", AllCnt);

    if (AllCnt != N * M * H) Answer = -1;
    return Answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cout << solve() << '\n';
    return 0;
}