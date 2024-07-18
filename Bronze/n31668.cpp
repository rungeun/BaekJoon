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
ll arr[sz];
ll Answer = INF;
int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M, K;

    cin >> N >> M >> K;

    Answer = M / N;
    Answer *= K;

    cout << Answer;
    return 0;
}