#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
int Answer;
int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, s = 0;
    while (cin >> n) {
        s += n;
    }
    Answer = s;
    cout << Answer;
    return 0;
}