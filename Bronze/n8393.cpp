#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
const int sz = 1 << 17;
int Answer = 0;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i < N + 1; i++) {
        Answer += i;
    }
    cout << Answer;
    return 0;
}