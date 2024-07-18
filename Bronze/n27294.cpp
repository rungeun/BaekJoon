#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const ll MOD = 1e9 + 7;
const int sz = 1 << 17;
const int INF = INT_MAX;
int Answer = 0;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, N;
    cin >> T >> N;

    if (N == 1 || (T < 12 || T > 16)) {
        Answer = 280;
    } else {
        Answer = 320;
    }
    cout << Answer;
    return 0;
}