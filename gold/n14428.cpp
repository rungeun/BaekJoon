#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const ll MOD = 1e9 + 7;
const int sz = 1 << 23;
const int INF = INT_MAX;
ll arr[sz], minT[sz];
int Answer = 0;
int N;
int update(int i, int v, int node = 1, int ns = 0, int ne = N - 1) {
    // index가 노드가 표현하는 구간과 상관없는 경우엔 무시한다.
    if (i < ns || ne < i) return minT[node];
    // 트리의 리프까지 내려온 경우
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

int find_index(int value, int s, int e) {
    for (int i = s; i <= e; ++i) {
        if (arr[i] == value) return i;
    }
    return -1;
}

int main(void) {
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
            arr[b - 1] = c;
        } else {
            int minq = query(b - 1, c - 1);
            Answer = find_index(minq, b - 1, c - 1) + 1;
            cout << Answer << '\n';
        }
    }
    return 0;
}