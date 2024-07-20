#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int sz = 400'010;
const int INF = INT_MAX;
int Answer = 0;
int sumT[sz];
vector<pair<int, int>> vec;
int N;

void update(int i, int node = 1, int ns = 0, int ne = N - 1) {
    if (i < ns || ne < i) return;
    sumT[node] += 1;
    if (ns == ne) return;
    int mid = (ns + ne) >> 1;
    update(i, node << 1, ns, mid);
    update(i, node << 1 | 1, mid + 1, ne);
}

int query(int s, int e, int node = 1, int ns = 0, int ne = N - 1) {
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return sumT[node];
    int mid = (ns + ne) >> 1;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, a, b;
    cin >> N >> M;

    vec.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> vec[i].first >> vec[i].second;
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < M; ++i) {
        Answer += query(vec[i].second, N - 1);
        update(vec[i].second - 1);
    }

    cout << Answer;
    return 0;
}
