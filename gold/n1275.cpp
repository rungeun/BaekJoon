#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int sz = 1 << 17;
const int INF = 0;
ll Answer = 0;
ll arr[sz], sumT[sz];

void update(int i, int val) {
    i += sz;
    sumT[i] = val;
    while (i > 1) {
        i >>= 1;
        sumT[i] = sumT[i << 1] + sumT[i << 1 | 1];
    }
}

ll query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return INF;
    if (s <= ns && ne <= e) return sumT[node];
    ll mid = (ns + ne) >> 1;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, M;
    ll x, y, a, b;
    cin >> N >> M;
    for (ll _ = 0; _ < N; _++) {
        cin >> arr[_];
        update(_, arr[_]);
    }

    for (ll _ = 0; _ < M; _++) {
        cin >> x >> y >> a >> b;
        if (x > y) {
            int temp;
            temp = x;
            x = y;
            y = temp;
        }
        Answer = query(x - 1, y - 1);
        update(a - 1, b);
        cout << Answer << '\n';
    }
    return 0;
}