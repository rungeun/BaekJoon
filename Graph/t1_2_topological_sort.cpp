#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;

vector<int> seen, order;
vector<vector<int>> vec;

void dfs(int here) {
    seen[here] = 1;
    for (int there : vec[here]) {
        if (!seen[there]) dfs(there);
    }
    order.push_back(here);
}

// vec에 주어진 그래프를 위상정렬한 결과를 반환한다.
// 그래프가 DAG가 아니라면 빈 벡터를 반환한다.
vector<int> topologicalSort() {
    int n = vec.size();
    seen = vector<int>(n, 0);
    order.clear();
    for (int i = 0; i < n; ++i)
        if (!seen[i]) dfs(i);
    reverse(order.begin(), order.end());

    // 만약 그래프가 DAG가 아니라면 정렬 결과에 역방향 간선이 있다.
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (vec[order[j]][order[i]]) {
                return vector<int>();
            }
        }
    }

    // 없는 경우라면 깊이 우선 탐색에서 얻은 순서를 반환한다.
    return order;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vec.resize(N);

    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;
        vec[s].push_back(e);
    }

    vector<int> result = topologicalSort();
    if (result.empty()) {
        cout << "The graph is not a DAG." << endl;
    } else {
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
