﻿#pragma GCC optimize("O3,Ofast,Unroll-loops")
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

void update_range(int node, int start, int end, int left, int right, ll diff) {
    update_lazy(node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        sumT[node] += (end - start + 1) * diff;
        if (start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right, diff);
    update_range(node * 2 + 1, mid + 1, end, left, right, diff);
    sumT[node] = sumT[node * 2] + sumT[node * 2 + 1];
}

ll query(int s, int e, int node = 1, int ns = 0, int ne = N - 1) {
    update_lazy(node, ns, ne);
    if (e < ns || ne < s) return 0;
    if (s <= ns && ne <= e) return sumT[node];
    int mid = (ns + ne) >> 1;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        update_range(1, 0, N - 1, i, i, value);
    }

    for (int i = 0; i < M + K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 2) {
            Answer = query(b - 1, c - 1);
            cout << Answer << '\n';
        } else {
            int d;
            cin >> d;
            update_range(1, 0, N - 1, b - 1, c - 1, d);
        }
    }

    return 0;
}
