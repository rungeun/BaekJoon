#include <iostream>
using namespace std;

int dp(int N, int* T, int* P) {}

int main(void) {
    int N, T[15] = {0}, P[15] = {0};
    cin >> N;

    for (int i = 0; i < N; i++) cin >> T[i] >> P[i];

    cout << dp(N, T, P);
    return 0;
}

int dp(int N, int* T, int* P) {
    // 메모이제이션
    int dp[16];
    return 0;
}