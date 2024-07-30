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

int solve() {
    int Answer = 0;
    char ch;
    cin >> N;
    FOR(_, N) {
        cin>>ch;
        Answer+= ch-'0';
    }
    return Answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cout << solve() << '\n';
    return 0;
}