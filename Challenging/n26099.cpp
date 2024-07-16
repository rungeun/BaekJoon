#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
//using ull = unsigned long long;
using ull = long long;
const ull INF = (1LL << 63) - 1;
ull Answer;
ull N;
map<pair<ull, ull>, ull> cache;  // key(a, b), value(a+b)
ull dp(ull a, ull b) {
    ull sum = a * 5 + b * 3;
    if (sum > N) return INF;
    if (sum == N) return a + b;
    pair<ull, ull> key = {a, b};
    if (cache.count(key)) return cache[key];
    ull ld = dp(a + 1, b);
    ull rd = dp(a, b + 1);
    return cache[key] = min(ld, rd);
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    Answer = dp(0, 0);
    if (Answer == INF)
        cout << "-1";
    else
        cout << Answer;
    return 0;
}