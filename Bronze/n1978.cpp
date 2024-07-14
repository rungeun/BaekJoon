#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
const int sz = 1 << 7;
int Answer = 0;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    int arr[sz];
    bool check;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        check = 1;
        if (arr[i] == 1) {
            continue;
        }
        for (int j = 2; j <= sqrt(arr[i]); j++) {
            if (arr[i] % j == 0) {
                check = 0;
                break;
            }
        }
        if (check) {
            Answer++;
        }
    }

    cout << Answer;
    return 0;
}