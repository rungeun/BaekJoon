#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
using namespace std;

int Answer;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, test_case;
    int count = 0;
    string str;
    cin >> N;
    for (test_case = 0; test_case < N; test_case++) {
        cin >> str;
        count = 0;
        Answer = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'O') {
                count++;
                Answer += count;
            } else {
                count = 0;
            }
        }
        cout << Answer << '\n';
    }
    return 0;
}