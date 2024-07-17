#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;  // 모듈러 값을 정의
const ll sz = 1000007;
ll tree[sz];
ll arr[sz];
ll Answer;

ll product(ll pos) {
    ll ret = 0;
    while (pos > 0) {
        ret = (ret * tree[pos]) / MOD;
        pos -= (pos & -pos);
    }
    return ret;
}

void update(ll pos, ll val) {
    while (pos < sz) {
        tree[pos] = (tree[pos] * val) / MOD;
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
        update(i, x);
    }

    for (ll q = 0; q < M + K; q++) {
        ll a;
        cin >> a;
        if (a == 1) {
            ll index, value;
            cin >> index >> value;
            update(index, value - arr[index]);
            arr[index] = value;
        } else {
            ll start, end;
            cin >> start >> end;
            ll startP = product(start - 1);
            ll endP = product(end);
            if (startP == 0) {
                TEST("0", startP);
                Answer = endP;
            } else {
                TEST("endP", endP);
                TEST("startP", startP);
                Answer = endP / startP;
            }

            cout << Answer << '\n';
        }
    }
    return 0;
}
