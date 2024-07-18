#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll MOD = 1e9 + 7;
const int INF = 1;
vector<ll> arr, mulT;

void update(int i, ll val, int sz) {
    i += sz;
    mulT[i] = val % MOD;
    while (i > 1) {
        i >>= 1;
        mulT[i] = (mulT[i << 1] * mulT[i << 1 | 1]) % MOD;
    }
}

ll query(int s, int e, int node, int ns, int ne) {
    if (e < ns || ne < s) return 1;
    if (s <= ns && ne <= e) return mulT[node];
    int mid = (ns + ne) >> 1;
    ll lmul = query(s, e, node << 1, ns, mid);
    ll rmul = query(s, e, node << 1 | 1, mid + 1, ne);
    return (lmul * rmul) % MOD;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    int sz = 1;
    while (sz < N) sz <<= 1;
    arr.resize(N);
    mulT.resize(sz * 2, 1);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        update(i, arr[i], sz);
    }

    for (int i = 0; i < M + K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(b - 1, c, sz); // 인덱스 변환
        } else {
            cout << query(b - 1, c - 1, 1, 0, sz - 1) << '\n'; // 인덱스 변환
        }
    }

    return 0;
}
