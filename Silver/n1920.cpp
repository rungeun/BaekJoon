#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
const int sz = 1 << 17;

bool Answer = 0;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    int arr[sz];
    int arr2[sz];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> arr2[i];
    }

    sort(arr, arr + N);

    bool check = 1;

    int l, r, mid;
    for (int si = 0; si < M; si++) {
        Answer = 0;
        l = 0;
        r = N - 1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (arr[mid] == arr2[si]) {
                Answer = 1;
                break;
            } else if (arr[mid] > arr2[si]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << Answer << '\n';
    }

    return 0;
}