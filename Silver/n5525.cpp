#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
int Answer = 0;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    string str;
    int k;
    cin >> N >> M >> str;
    for (int i = 0; i < M; i++) {
        k = 0;
        while (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I' && k < N && i + 2 < M) {
            k++;
            i += 2;
            if (k == N) {
                Answer++;
                k--;
            }
        }
    }
    cout << Answer;
    return 0;
}