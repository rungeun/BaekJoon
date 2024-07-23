#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr int sz = 1 << 17;
constexpr int INF = INT_MAX;

int N, M;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
vector<vector<bool>> vied;
vector<vector<int>> adj;
vector<vector<int>> adj2;

void dfs(int r, int c) {
    vied[r][c] = true;
    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (0 <= nr && nr < N && 0 <= nc && nc < M && !vied[nr][nc] && adj[nr][nc] > 0) {
            dfs(nr, nc);
        }
    }
}

// 완료
void copy() {
    vied = vector<vector<bool>>(N, vector<bool>(M, false));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (adj[r][c] == 0) {
                vied[r][c] = true;  // 0인 곳은 방문 처리를 미리 해둠
            }
        }
    }
}

// 완료
int dfsAll() {
    int count = 0;
    copy();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vied[i][j] && adj[i][j] > 0) {
                dfs(i, j);
                count++;
            }
        }
    }
    return count;
}

// 완료
void ice() {
    adj2 = vector<vector<int>>(N, vector<int>(M, 0));  // adj2는 빙하 녹음을 임시 저장
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {        
            if (adj[r][c] > 0) {             
                for (int k = 0; k < 4; k++) {  
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (0 <= nr && nr < N && 0 <= nc && nc < M && adj[nr][nc] == 0) {
                        adj2[r][c]++;
                    }
                }
            }
        }
    }
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            adj[r][c] = max(0, adj[r][c] - adj2[r][c]);  // 녹은 빙하 값 빼주기, 음수 방지
        }
    }
}

// 완료
int solve() {
    int Answer = 0;
    cin >> N >> M;
    adj.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> adj[i][j];
        }
    }

    while (dfsAll() == 1) {
        ice();
        Answer++;
    }
    return Answer;
}

// 완료
int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cout << solve();
    return 0;
}