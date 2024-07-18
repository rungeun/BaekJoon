#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const ll MOD = 1e9 + 7;
const int sz = 1 << 17;
const int INF = INT_MAX;

int Answer = 0;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    ll N;
    ll count = 0;
    cin >> N;
    count = N * (N - 1) * (N - 2);
    count /= 6;
    cout << count << '\n' << '3';
    return 0;
}

/*
MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n - 2
        for j <- i + 1 to n - 1
            for k <- j + 1 to n
                sum <- sum + A[i] × A[j] × A[k]; # 코드1
    return sum;
}
*/