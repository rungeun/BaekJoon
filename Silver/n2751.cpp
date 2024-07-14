#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
const int sz = 1 << 20;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    int arr[sz];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}