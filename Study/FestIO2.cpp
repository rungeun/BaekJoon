#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const ll MOD = 1e9+7;
const int sz = 1 << 17;
const int INF = INT_MAX;

ll a[sz];
int Answer = 0;
// 1<<7  : 128
// 1<<17 : 131,072
// 1<<20 : 1,048,576
// 1<<24 : 16,777,216
// 1<<27 : 134,217,728
// 1<<31 - 1: 2,147,483,647(int 자료형의 상한값)
// const int INF = (1 << 30) - 1 + (1 << 30);
// 1<<63 - 1 : 9,223,372,036,854,775,807(long long자료형의 상한값)
// const long long INF = (1LL << 63) - 1; // 2^63 - 1
// 1<<64 - 1 : 18,446,744,073,709,551,615 (unsigned long long자료형의 상한값)
// const ull INF = (1ULL << 63) - 1 + (1ULL << 63); // 2^64 - 1

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    cin >> N;
    for (int _ = 0; _ < N; _++) {
    }
    cout << Answer;
    return 0;
}