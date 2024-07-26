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
vector<vector<int>> graph;
vector<vector<int>> result;

void bfs(int now) {
    queue<int> q;
    vector<int> vied(N, 0);
    q.push(now);
    vied[now] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        FOR(i, N) {
            if (graph[node][i] == 1 && !vied[i]) {
                vied[i] = 1;
                q.push(i);
                result[now][i] = 1;
            }
        }
    }

    FOR(i, N) {
        if (vied[i]) {
            FOR(j, N) {
                if (graph[i][j] == 1 && vied[j] && j == now) {
                    result[now][now] = 1;
                }
            }
        }
    }
}

void solve() {
    int Answer = 0;
    cin >> N;
    graph.assign(N, vector<int>(N, 0));
    result.assign(N, vector<int>(N, 0));
    FOR(i, N) FOR(j, N) cin >> graph[i][j];
    FOR(_, N) bfs(_);
    FOR(i, N) {FOR(j, N) cout << result[i][j] << ' '; cout << '\n';}
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}