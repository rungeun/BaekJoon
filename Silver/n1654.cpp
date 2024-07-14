// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/stdc++.h>
// #define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
// using namespace std;
// const int sz = 1 << 20;

// int Answer=0;

// int main(void) {
//     ios::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     int arr[sz];
//     int N, K;
//     long long l, r, mid, cut = 0;
//     cin >> K >> N;
    
//     for(int i=0; i<K; i++){
//         cin>>arr[i];
//     }

//     sort(arr, arr + K);

//     l = 0;
//     r = arr[N - 1];

//     while (l < r) {
//         cut = 0;
//         mid = (l + r) >> 2;
//         for (int i = 0; i < K; i++) {
//             cut += arr[i] / mid;
//         }
//         if (cut < N) {
//             r = mid - 1;
//         } else {
//             Answer = mid;
//             mid= +1;
//         }
//     }

//     cout << Answer;
//     return 0;
// }

#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
const long long sz = 1 << 20;
long long arr[sz];
long long Answer = 0;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, K;
    long long l, r, mid, cut;
    cin >> K >> N;
    
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + K);

    l = 1; // 0으로 나누는 오류를 피하기 위해 1로 설정
    r = arr[K - 1];

    while (l <= r) {
        cut = 0;
        mid = (l + r) / 2;
        for (int i = 0; i < K; i++) {
            cut += arr[i] / mid;
        }
        if (cut < N) {
            r = mid - 1;
        } else {
            Answer = mid;
            l = mid + 1;
        }
    }

    cout << Answer;
    return 0;
}


