#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(10, 0));

    // 초기 조건: 길이가 1인 경우
    for (int k = 0; k < 10; ++k) {
        dp[1][k] = 1;
    }

    // DP 계산
    for (int n = 2; n <= N; ++n) {
        for (int k = 0; k < 10; ++k) {
            for (int j = 0; j <= k; ++j) {
                dp[n][k] = (dp[n][k] + dp[n - 1][j]) % MOD;
            }
        }
    }

    // 결과 계산
    int result = 0;
    for (int k = 0; k < 10; ++k) {
        result = (result + dp[N][k]) % MOD;
    }

    cout << result << '\n';
    return 0;
}
//햄버거 국밥 찌게(김치 된장) 짱깨 국수 치킨 백숙 파전 분식
