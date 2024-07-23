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
int N;
vector<vector<int>> vec1;
int count1 = 0;
vector<vector<int>> vec2;
int count2 = 0;

void dfs(int y, int x) {
    int k = vec1[y][x];
    vec1[y][x] = 0;
    if (y - 1 >= 0 && vec1[y - 1][x] == k) dfs(y - 1, x);
    if (y + 1 < N && vec1[y + 1][x] == k) dfs(y + 1, x);
    if (x - 1 >= 0 && vec1[y][x - 1] == k) dfs(y, x - 1);
    if (x + 1 < N && vec1[y][x + 1] == k) dfs(y, x + 1);
}

void dfs2(int y, int x) {
    int k = vec2[y][x];
    vec2[y][x] = 0;
    if (y - 1 >= 0 && vec2[y - 1][x] == k) dfs2(y - 1, x);
    if (y + 1 < N && vec2[y + 1][x] == k) dfs2(y + 1, x);
    if (x - 1 >= 0 && vec2[y][x - 1] == k) dfs2(y, x - 1);
    if (x + 1 < N && vec2[y][x + 1] == k) dfs2(y, x + 1);
}

void dfsAll() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vec1[i][j] != 0) {
                dfs(i, j);
                count1++;
            }
            if (vec2[i][j] != 0) {
                dfs2(i, j);
                count2++;
            }
        }
    }
}

void solve() {
    char ch;
    cin >> N;
    vec1 = vector<vector<int>>(N, vector<int>(N, 0));
    vec2 = vector<vector<int>>(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ch;
            if (ch == 'R') {
                vec1[i][j] = 1;
                vec2[i][j] = 1;
            } else if (ch == 'G') {
                vec1[i][j] = 2;
                vec2[i][j] = 1;
            } else if (ch == 'B') {
                vec1[i][j] = 3;
                vec2[i][j] = 2;
            }
        }
    }
    dfsAll();
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    cout << count1 << ' ' << count2;
    return 0;
}
