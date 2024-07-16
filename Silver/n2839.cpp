#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;

const int sz = 1 << 13;
const int INF = 1e9 + 7;
int Answer;
int N;
map<pair<int, int>, int> cache;  // key(a, b), value(a+b)
int dp(int a, int b) {
    int sum = a * 5 + b * 3;
    if (sum > N) return INF;
    if (sum == N) return a + b;
    pair<int, int> key = {a, b};
    if (cache.count(key)) return cache[key];
    int ld = dp(a + 1, b);
    int rd = dp(a, b + 1);
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