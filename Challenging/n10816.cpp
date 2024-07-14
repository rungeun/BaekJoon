#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
const int sz = 1 << 19;
ll a[sz];
ll b[sz];
ll ct[sz];

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    ll target, l, r, mid, li, ri;
    cin >> N;
    for (int _ = 0; _ < N; _++) {
        cin >> a[_];
    }
    cin >> M;
    for (int _ = 0; _ < M; _++) {
        cin >> b[_];
    }
    sort(a, a + N);

    for (int i = 0; i < M; i++) {
        target = b[i];
        l = 0, r = N;
        while (l < r) {
            mid = (l + r) / 2;
            if (a[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        li = l;

        l = 0, r = N;
        while (l < r) {
            mid = (l + r) / 2;
            if (a[mid] <= target)
                l = mid + 1;
            else
                r = mid;
        }
        ri = l;
        ct[i] = ri - li;
    }

    for (int _ = 0; _ < M; _++) {
        cout << ct[_] << ' ';
    }
    return 0;
}

// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/stdc++.h>
// #define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
// using namespace std;
// using ll = long long;
// const int sz = 1 << 19;
// ll a[sz];
// ll b[sz];
// ll ct[sz];
// int main(void) {
//     ios::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     int N, M;
//     ll l, r, mid, li, ri;
//     cin >> N;
//     for (int _ = 0; _ < N; _++) {
//         cin >> a[_];
//     }
//     cin >> M;
//     for (int _ = 0; _ < M; _++) {
//         cin >> b[_];
//     }
//     sort(a, a + N);

//     for (int target = 0; target < M; target++) {
//         l = 0;
//         r = N - 1;
//         while (l <= r) {
//             mid = (l + r) / 2;
//             if (a[mid] < b[target]) {
//                 l = mid + 1;
//             } else if (a[mid] > b[target]) {
//                 r = mid - 1;
//             } else {
//                 li = mid - 1;
//                 ri = mid + 1;
//                 ct[target] = 1;
//                 while (li >= 0 && a[li] == b[target]) {
//                     ct[target]++;
//                     li--;
//                 }
//                 while (ri < N && a[ri] == b[target]) {
//                     ct[target]++;
//                     ri++;
//                 }
//                 break;
//             }
//         }
//     }
//     for (int _ = 0; _ < M; _++) {
//         cout << ct[_] << ' ';
//     }
//     return 0;
// }