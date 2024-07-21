#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
vector<vector<int>> vec;
vector<bool> vied;

int Answer = 0;

void dfs(int here) {
    vied[here] = true;
    for (int _ = 0; _ < vec[here].size(); _++) {
        int there = vec[here][_];
        if (!vied[there]) {
            dfs(there);
        }
    }
}

int dfsAll() {
    int count = 0;
    for (int _ = 1; _ < vied.size(); _++) {
        if (!vied[_]) {
            dfs(_);
            count++;
        }
    }
    return count;
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M, A, B;
    cin >> N >> M;
    vec.resize(N + 1);
    vied.resize(N + 1, false);
    for (int _ = 0; _ < M; _++) {
        cin >> A >> B;
        vec[A].push_back(B);
        vec[B].push_back(A);
    }
    Answer = dfsAll();
    cout << Answer;
    return 0;
}