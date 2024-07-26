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
constexpr int sz = 1 << 7;
constexpr int INF = 0x7fffffff;
int N = 101;

int board[sz];
int dist[sz];
queue<int> q;

int bfs(int start) {
    memset(dist, -1, sizeof(dist));
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (int i = 1; i < 6 + 1; i++) {
            int there = here + i;
            if (there > 100) continue;

            if (board[there] != 0) {
                there = board[there];
            }

            if (dist[there] == -1) {
                q.push(there);
                dist[there] = dist[here] + 1;
                if (there == 100) {
                    return dist[there];
                }
            }
        }
    }
    return -1;
}

int solve() {
    int Answer = 0;
    int a, b;
    int x, y;
    cin >> a >> b;
    FOR(_, a + b) {
        cin >> x >> y;
        board[x] = y;
    }

    Answer = bfs(1);
    // for (int i = 1; i < N + 1; i++) {
    //     cout << dist[i] << ' ';
    // }
    return Answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cout << solve() << '\n';
    return 0;
}