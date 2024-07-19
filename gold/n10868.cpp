#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;

const int sz = 1 << 17;
const int INF = INT_MAX;
int Answer = 0;
int arr[sz], minT[sz];

void update(int i, int val) {
    i += sz;
    minT[i] = val;
    while (i > 1) {
        i >>= 1;
        minT[i] = min(minT[i << 1], minT[i << 1 | 1]);
    }
}

int query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return INF;
    if (s <= ns && ne <= e) return minT[node];
    int mid = (ns + ne) >> 1;
    return min(query(s, e, node << 1, ns, mid), query(s, e, node << 1 | 1, mid + 1, ne));
}



int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    int a, b;
    cin >> N >> M;
    for (int _ = 0; _ < N; _++) {
        cin >> arr[_];
        update(_, arr[_]);
    }
    for (int _ = 0; _ < M; _++) {
        cin >> a >> b;
        Answer = query(a - 1, b - 1);
        cout << Answer << '\n';
    }
    return 0;
}