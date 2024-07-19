#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int sz = (1 << 21);
const int INF = 0;
ll Answer = 0;
ll sumT[sz<<2];

void update(int i, ll val) {
    i += sz;
    sumT[i] = val;
    while (i > 1) {
        i >>= 1;
        sumT[i] = sumT[i << 1] + sumT[i << 1 | 1];
    }
}

ll query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return sumT[node];
    ll mid = (ns + ne) >> 1;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, M;
    ll m, i, j;
    cin >> N >> M;
    for (ll _ = 0; _ < N; _++) {
        update(_, 0);
    }
    for (ll _ = 0; _ < M; _++) {
        cin >> m >> i >> j;
        if (m == 0) {
            if (i > j) {
                int temp;
                temp = i;
                i = j;
                j = temp;
            }
            Answer = query(i - 1, j - 1);

            cout << Answer << '\n';
        } else {
            update(i - 1, j);
        }
    }
    return 0;
}