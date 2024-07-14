#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
using namespace std;

int Answer = 0;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c;
    int k;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        Answer = 0;
        cin >> a >> b >> c;
        a = min(a, b);
        Answer = min(a, c);
        cout << Answer << '\n';
    }

    return 0;
}