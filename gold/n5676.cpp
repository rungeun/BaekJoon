#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int mulT[400001];
int N;

int update(int i, int v, int node = 1, int ns = 0, int ne = N - 1) {
    if (i < ns || ne < i) return mulT[node];
    if (ns == ne) return mulT[node] = v;
    int mid = (ns + ne) >> 1;
    return mulT[node] = update(i, v, node << 1, ns, mid) * update(i, v, node << 1 | 1, mid + 1, ne);
}

int queryMul(int s, int e, int node = 1, int ns = 0, int ne = N - 1) {
    if (e < ns || ne < s) return 1;
    if (s <= ns && ne <= e) return mulT[node];
    int mid = (ns + ne) >> 1;
    return queryMul(s, e, node << 1, ns, mid) * queryMul(s, e, node << 1 | 1, mid + 1, ne);
}

void updateSet(int i, int x) {
    if (x > 0) {
        update(i, 1);
    } else if (x < 0) {
        update(i, -1);
    } else {
        update(i, 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int K;
    int x;
    char a;
    int b, c;
    while (1) {
        cin >> N >> K;
        if (cin.eof()) break;
        for (int _ = 0; _ < N; _++) {
            cin >> x;
            updateSet(_, x);
        }
        for (int _ = 0; _ < K; _++) {
            cin >> a >> b >> c;
            if (a == 'C') {
                updateSet(b - 1, c);
            } else {
                int mul = queryMul(b - 1, c - 1);
                if (mul > 0) {
                    cout << '+';
                } else if (mul < 0) {
                    cout << '-';
                } else {
                    cout << '0';
                }
            }
        }
        cout << '\n';
    }
    return 0;
}