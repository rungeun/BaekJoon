#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;

const ll sz = 1000007;
ll tree[sz];
ll arr[sz];

ll sum(ll pos) {
    ll ret = 0;
    while (pos > 0) {
        ret += tree[pos];
        pos -= (pos & -pos);
    }
    return ret;
}

void update(ll pos, ll val) {
    while (pos < sz) {  // pos < sz로 배열의 크기 내에서만 업데이트
        tree[pos] += val;
        pos += (pos & -pos);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M, K;
    cin >> N >> M >> K;

    for (ll i = 1; i <= N; i++) {
        ll x;
        cin >> x;
        arr[i] = x;
        update(i, x);  // 초기 값 업데이트
    }

    for (ll q = 0; q < M + K; q++) {
        ll a;
        cin >> a;
        if (a == 1) {
            ll index, value;
            cin >> index >> value;
            update(index, value - arr[index]);  // 펜윅 트리에 차이만큼 반영
            arr[index] = value;                 // 배열 값 업데이트
        } else {
            ll start, end;
            cin >> start >> end;
            ll Answer = sum(end) - sum(start - 1);
            cout << Answer << '\n';
        }
    }
    return 0;
}
