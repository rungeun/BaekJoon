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
bool arr[sz];
int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, test_count;
    cin >> T;
    for (test_count = 0; test_count < T; test_count++) {
        int P, M, K;
        Answer = 0;
        cin >> P >> M;
        for (int _ = 1; _ < M + 1; _++) {
            arr[_] = 0;
        }

        for (int _ = 0; _ < P; _++) {
            cin >> K;
            if (!arr[K]) {  // 채워 넣기
                arr[K] = 1;
            } else {  // 차있다면 카운트
                Answer++;
            }
        }
        cout << Answer << '\n';
    }
    return 0;
}