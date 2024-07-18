#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1;
int sz = 1;
vector<ll> arr;
vector<ll> mulT;
int Answer = 0;

void update(int i, int val) {
    i += sz;
    mulT[i] = val % MOD;
    while (i > 1) {
        i >>= 1;
        ll lmulT = mulT[i << 1] % MOD;
        ll rmulT = mulT[i << 1 | 1] % MOD;
        mulT[i] = (lmulT * rmulT) % MOD;
        //mulT[i] = ((mulT[i << 1] % MOD) * (mulT[i << 1 | 1] % MOD)) % MOD;
    }
}

int query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 1;
    if (s <= ns && ne <= e) return mulT[node];
    ll mid = (ns + ne) >> 1;
    ll lmul = query(s, e, node << 1, ns, mid) % MOD;
    ll rmul = query(s, e, node << 1 | 1, mid + 1, ne) % MOD;
    return (lmul * rmul) % MOD;
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    while (sz < N) sz <<= 1;
    arr.resize(N);
    mulT.resize(sz * 2, 1);

    for (int _ = 0; _ < N; _++) {
        cin >> arr[_];
        update(_, arr[_]);
    }
    int a, b, c;
    for (int _ = 0; _ < M + K; _++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b - 1, c);
        } else {
            Answer = query(b - 1, c - 1);
            cout << Answer << '\n';
        }
    }
    return 0;
}