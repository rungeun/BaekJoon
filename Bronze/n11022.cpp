#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
const int sz = 1 << 17;
int Answer = 0;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    int a, b;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        cin >> a >> b;
        Answer = a + b;

        cout << "Case #" << testcase + 1 << ": " << Answer << '\n';
    }
    return 0;
}