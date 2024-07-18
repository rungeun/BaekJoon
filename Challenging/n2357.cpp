#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int sz = 1 << 22;
int arr[sz], max_tree[sz << 1], min_tree[sz << 1];

// 세그먼트 트리 업데이트 함수 (최댓값용)
void update_max(int i, int val) {
    i += sz;
    max_tree[i] = val;
    while (i > 1) {
        i >>= 1;
        max_tree[i] = max(max_tree[i << 1], max_tree[i << 1 | 1]);
    }
}

// 세그먼트 트리 업데이트 함수 (최솟값용)
void update_min(int i, int val) {
    i += sz;
    min_tree[i] = val;
    while (i > 1) {
        i >>= 1;
        min_tree[i] = min(min_tree[i << 1], min_tree[i << 1 | 1]);
    }
}

// 세그먼트 트리 쿼리 함수 (최댓값용)
int query_max(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return INT_MIN;
    if (s <= ns && ne <= e) return max_tree[node];
    int mid = (ns + ne) >> 1;
    return max(query_max(s, e, node << 1, ns, mid), query_max(s, e, node << 1 | 1, mid + 1, ne));
}

// 세그먼트 트리 쿼리 함수 (최솟값용)
int query_min(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return INT_MAX;
    if (s <= ns && ne <= e) return min_tree[node];
    int mid = (ns + ne) >> 1;
    return min(query_min(s, e, node << 1, ns, mid), query_min(s, e, node << 1 | 1, mid + 1, ne));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, M;
    cin >> n >> M;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        update_max(i, arr[i]);
        update_min(i, arr[i]);
    }

    // 단순히 전체 범위에 대한 최댓값과 최솟값을 쿼리합니다
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        int min_val = query_min(a - 1, b - 1);
        int max_val = query_max(a - 1, b - 1);

        cout << min_val << ' ' << max_val << '\n';
    }
    return 0;
}