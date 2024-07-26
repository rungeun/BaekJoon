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
int sr, sc;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

vector<vector<bool>> vec;
vector<vector<bool>> dis;
vector<vector<int>> dist;

void bfs(int r, int c) {
    queue<pii> q;
    dis[r][c] = false;
    dist[r][c] = 0;
    q.emplace(r, c);
    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();
        FOR(k, 4) {
            int nr = cr + dr[k];
            int nc = cc + dc[k];
            if (0 <= nr && nr < N && 0 <= nc && nc < M && dis[nr][nc]) {
                q.emplace(nr, nc);
                dist[nr][nc] = dist[cr][cc] + 1;
                dis[nr][nc] = false;
            }
        }
    }
}

void Answer() {
    FOR(i, N) {
        FOR(j, M) {
            if (vec[i][j]) {                                  // 벽이 아니라면
                if (dist[i][j] == 0 && i != sr && j != sc) {  // 탐색하지 못했다면
                    cout << "-1" << ' ';
                } else {  // 탐색 했다면 거리 출력
                    cout << dist[i][j] << ' ';
                }
            } else {
                cout << '0' << ' ';  // 벽  출려
            }
        }
        cout << '\n';
    }
}

void solve() {
    cin >> N >> M;
    vec.assign(N, vector<bool>(M, false));
    dis.assign(N, vector<bool>(M, false));
    dist.assign(N, vector<int>(M, -1));
    int x;

    FOR(i, N) {
        FOR(j, M) {
            cin >> x;
            if (x == 2) {
                sr = i;
                sc = j;
                dis[i][j] = true;
                vec[i][j] = true;
            } else if (x == 1) {
                dis[i][j] = true;  // true는 이동 가능 //false는 이동 불가능
                vec[i][j] = true;
            }
        }
    }

    bfs(sr, sc);
    Answer();
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}