#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
using namespace std;

int BruteForce(int N);

int main(void) {
    int N;
    cin >> N;
    cout << BruteForce(N);
    return 0;
}

int BruteForce(int N) {
    int tmp, sum;
    for (int i = 1; i < N; i++) {
        tmp = sum = i;
        while (tmp != 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == N) {
            return i;
        }
    }
    return 0;
}
