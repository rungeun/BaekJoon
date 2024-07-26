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
    string str;
    bool A = false, F = false, C = false;
    cin >> str;
    int M = str.size();

    for (int i = 0; i < M; i++) {
        if (str[i] == 'A') {
            A = true;
        } else if (str[i] == 'F') {
            if (!A) {
                return "Good";
            }
            F = true;
        } else if (str[i] == 'C') {
            if (!A || !F) {
                return "Good";
            }
            C = true;

            // 확인 이후의 문자가 조건에 맞는지 판단
            if (i == M - 1 || (i == M - 2 && 'A' <= str[M - 1] && str[M - 1] <= 'F')) {
                return "Infected!";
            } else {
                return "Good";
            }
        }
    }
    return "Good"; // 기본 반환 값
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cout << solve() << '\n';
    }
    return 0;
}
