#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int sz = 400'010;
const int INF = INT_MAX;
int Answer = 0;
int arr[sz], minT[sz];
int N;
int update(int i, int v, int node = 1, int ns = 0, int ne = N - 1) {
    if (i < ns || ne < i) return minT[node];
    if (ns == ne) return minT[node] = v;
    int mid = (ns + ne) >> 1;
    return minT[node] = min(update(i, v, node << 1, ns, mid), update(i, v, node << 1 | 1, mid + 1, ne));
}

int query(int s, int e, int node = 1, int ns = 0, int ne = N - 1) {
    if (e < ns || ne < s) return INF;
    if (s <= ns && ne <= e) return minT[node];
    int mid = (ns + ne) >> 1;
    return min(query(s, e, node << 1, ns, mid), query(s, e, node << 1 | 1, mid + 1, ne));
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int M;
    int a, b, c;
    cin >> N;

    for (int _ = 0; _ < N; _++) {
        cin >> arr[_];
        update(_, arr[_]);
    }
    cin >> M;
    for (int _ = 0; _ < M; _++) {
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