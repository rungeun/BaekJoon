#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
#define ALL(x) x.begin(), x.end()
#define FOR(y, x) for (int y = 0; y < (x); y++)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr int sz = 1 << 17;
constexpr int INF = 0x7fffffff;

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

string solve() {
    string Answer;
    char ch;
    cin >> ch;
    switch (ch) {
        case 'M':
            Answer = "MatKor";
            break;

        case 'W':
            Answer = "WiCys";
            break;

        case 'C':
            Answer = "CyKor";
            break;

        case 'A':
            Answer = "AlKor";
            break;

        case '$':
            Answer = "$clear";
            break;
    }

    return Answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    // int testCase;
    // cin >> testCase;
    // for (int _ = 0; _ < testCase; _++) {
    cout << solve();  //<< '\n';
    //  }
    return 0;
}