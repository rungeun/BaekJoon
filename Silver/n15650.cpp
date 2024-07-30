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
int arr[8];
bool vi[8];

void rec(int dep, int s) {
    if (dep == M) {
        FOR(_, M) cout << arr[_] + 1 << ' ';
        cout << '\n';
        return;
    }
    for (int i = s; i < N; i++) {
        if (!vi[i]) {
            vi[i] = true;
            arr[dep] = i;
            rec(dep + 1, i + 1);
            vi[i] = false;
        }
    }
}

void solve() {
    int Answer = 0;
    cin >> N >> M;
    rec(0, 0);
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}