#pragma GCC optimize("O3,Ofast,Unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int sz = 4000001;
ll sumT[sz];
ll lazy[sz];
ll Answer;
int N;

void update_lazy(int node, int s, int e) {
    if (lazy[node] != 0) {
        sumT[node] += (e - s + 1) * lazy[node];
        if (s != e) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int s, int e, int ns, int ne, ll v) {
    update_lazy(node, s, e);
    if (e < ns || ne < s) {
        return;
    }
    if (ns <= s && e <= ne) {
        sumT[node] += (e - s + 1) * v;
        if (s != e) {
            lazy[node * 2] += v;
            lazy[node * 2 + 1] += v;
        }
        return;
    }
    int mid = (s + e) / 2;
    update_range(node * 2, s, mid, ns, ne, v);
    update_range(node * 2 + 1, mid + 1, e, ns, ne, v);
    sumT[node] = sumT[node * 2] + sumT[node * 2 + 1];
}

ll query(int s, int e, int node = 1, int ns = 0, int ne = N - 1) {
    update_lazy(node, ns, ne);
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return sumT[node];
    ll mid = (ns + ne) >> 1;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int M, K, v;
    int a, b, c, d;
    cin >> N >> M >> K;
    for (int _ = 0; _ < N; _++) {
        cin >> v;
        update_range(1, 0, N - 1, _, _, v);
    }

    for (int _ = 0; _ < M + K; _++) {
        cin >> a >> b >> c;
        if (a == 2) {
            Answer = query(b - 1, c - 1);
            cout << Answer << '\n';
        } else {
            cin >> d;
            update_range(1, 0, N - 1, b - 1, c - 1, d);
        }
    }

    return 0;
}