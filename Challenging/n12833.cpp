#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
int Answer;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int A, B, C;
    cin >> A >> B >> C;
    Answer = A ^ B;
    for (int i = 0; i < C - 1; i++) {
        Answer = Answer ^ B;
    }
    cout << Answer;
    return 0;
}
