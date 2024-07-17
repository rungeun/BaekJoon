#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;

struct FenwickTree {
    vector<int> tree;
    FenwickTree(int n) : tree(n + 1) {}

    // A[0...pos]의 부분합을 구한다.
    int sum(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    // A[pos]에 val을 더한다.
    void add(int pos, int val) {
        while (pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    FenwickTree fenwick(N);
    vector<int> arr(N + 1);  // 1부터 시작하기 위해 크기를 N+1로 설정

    // 수열 입력 받기
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        fenwick.add(i, arr[i]);
    }

    // 각 쿼리 처리
    for (int q = 0; q < M; q++) {
        int i, j;
        cin >> i >> j;
        int sum_j = fenwick.sum(j);
        int sum_i = fenwick.sum(i - 1);
        cout << sum_j - sum_i << '\n';
    }

    return 0;
}
