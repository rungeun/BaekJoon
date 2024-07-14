#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    string n;
    int count[10] = {0};
    cin >> n;
    for (int i = 0; i < n.size(); i++) {
        count[n[i] - 48]++;
    }
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < count[i]; j++) {
            cout << i;
        }
    }
    return 0;
}