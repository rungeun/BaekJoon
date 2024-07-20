#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = INT_MAX;
const int sz = 100000 * 4;
int N, M;
int arr[100000];
pair<int, int> segTree[sz];  // {value, index}

void update(int idx, int value, int node = 1, int start = 0, int end = N - 1) {
    if (start == end) {
        arr[idx] = value;
        segTree[node] = {value, idx};
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(idx, value, 2 * node, start, mid);
        } else {
            update(idx, value, 2 * node + 1, mid + 1, end);
        }
        segTree[node] = min(segTree[2 * node], segTree[2 * node + 1]);
    }
}

pair<int, int> query(int l, int r, int node = 1, int start = 0, int end = N - 1) {
    if (r < start || end < l) {
        return {INF, INF};
    }
    if (l <= start && end <= r) {
        return segTree[node];
    }
    int mid = (start + end) / 2;
    return min(query(l, r, 2 * node, start, mid), query(l, r, 2 * node + 1, mid + 1, end));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx, value;
            cin >> idx >> value;
            update(idx - 1, value);
        } else if (type == 2) {
            pair<int, int> result = query(0, N - 1);
            cout << result.second + 1 << '\n';
        }
    }

    return 0;
}
