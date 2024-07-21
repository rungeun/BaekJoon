#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;

vector<vector<bool>> vi;
int Answer = 0;
int N, M;
// 깊이 우선 탐색
void dfs(int y, int x) {
    // cout << x << ',' << y << '\n';
    vi[y][x] = true;
    // 모든 인접 정점을 순회
    if (y - 1 >= 0) {  // 상
        if (!vi[y - 1][x]) {
            dfs(y - 1, x);
        }
    }
    if (y + 1 < N) {  // 하
        if (!vi[y + 1][x]) {
            dfs(y + 1, x);
        }
    }
    if (x - 1 >= 0) {  // 좌
        if (!vi[y][x - 1]) {
            dfs(y, x - 1);
        }
    }
    if (x + 1 < M) {  // 우
        if (!vi[y][x + 1]) {
            dfs(y, x + 1);
        }
    }
}

void dfsAll() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vi[i][j]) {
                dfs(i, j);
                Answer++;
            }
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, K, X, Y;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        Answer = 0;
        cin >> M >> N >> K;
        vi = vector<vector<bool>>(N, vector<bool>(M, true));
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            vi[Y][X] = false;
        }
        dfsAll();
        cout << Answer << '\n';
    }
    return 0;
}