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
int N;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};
vector<vector<bool>> dis;
vector<int> ct;
int p = 0;
int bfs(int r, int c) {
    int count = 0;
    queue<pii> q;
    dis[r][c] = true;
    q.emplace(r, c);
    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();
        FOR(k, 4) {
            int nr = cr + dr[k];
            int nc = cc + dc[k];
            if (0 <= nr && nr < N && 0 <= nc && nc < N && !dis[nr][nc]) {
                q.emplace(nr, nc);
                dis[nr][nc] = true;
                count++;
            }
        }
    }
    return count + 1;
}
void bfsAll() {
    FOR(i, N) {
        FOR(j, N) {
            if (!dis[i][j]) {
                ct.push_back(bfs(i, j));
                p++;
            }
        }
    }
    sort(ALL(ct));
}
void solve() {
    int Answer = 0;
    cin >> N;
    dis.assign(N, vector<bool>(N, false));
    int x;
    string str;
    FOR(i, N) {
        cin >> str;
        FOR(j, N) {
            dis[i][j] = (str[j] == '0');  // true = 미방문
        }
    }
    bfsAll();
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    cout << p << '\n';
    FOR(_, p) cout << ct[_] << '\n';
    return 0;
}