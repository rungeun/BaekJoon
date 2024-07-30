#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
using namespace std;

int N, M;
int arr[8];       // 선택된 숫자
bool v[8] = {0};  // 방문 여부

void dfs(int k) {
    // 종료 조건
    if (k == M) {
        for (int i = 0; i < M; i++) cout << arr[i] + 1 << ' ';
        cout << '\n';
        return;
    }
    // 0부터 N-1까지의 숫자를 순회
    for (int i = 0; i < N; i++) {
        if (!v[i]) {       // 방문하지 않은 경우
            arr[k] = i;    // 현재 깊이에 숫자 i를 저장
            v[i] = true;   // 방문 처리
            dfs(k + 1);    // 다음 깊이로 재귀 호출
            v[i] = false;  // 방문 처리 해제
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    dfs(0);
}