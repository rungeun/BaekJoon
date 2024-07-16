#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int Answer = 0;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    queue<int> qu;
    cin >> N;
    for (int _ = 1; _ < N + 1; _++) {
        qu.push(_);
    }

    while (qu.size() != 1) {
        qu.pop();
        qu.push(qu.front());
        qu.pop();
    }
    Answer = qu.front();
    cout << Answer;
    return 0;
}