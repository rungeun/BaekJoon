#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
using namespace std;

int N, M;
int Answer[8] = {11};
bool v[8] = {0};

void dfs(int k) {
    bool check = 0;
    if (M == k) {
        for (int i = 0; i < M; i++) {
            cout << Answer[i] + 1 << ' ';
            check = 1;
        }
        if (check) {
            cout << '\n';
        }
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!v[i]) {
            Answer[k] = i;
            v[i] = 1;
            dfs(k + 1);
            v[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> N >> M;

    dfs(0);
    return 0;
}