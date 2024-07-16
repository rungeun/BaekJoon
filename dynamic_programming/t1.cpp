#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int sz = 1 << 7;
int cache[sz][sz];
int board[sz][sz];
int n;

int jump(int y, int x) {
    // 기저 사례: 게임판 밖을 벗어난 경우
    if (y >= n || x >= n) {
        return 0;
    }
    // 기저 사례: 마지막 칸에 도착한 경우
    if (y == n - 1 && x == n - 1) {
        return 1;
    }
    int& ret = cache[y][x];
    if (ret != -1) return ret;

    int jumpSize = board[y][x];
    return ret = jump(y + jumpSize, x) || jump(y, x + jumpSize);
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    if (jump(0, 0)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
// 메모이제이션

// 재귀함수로 모든 경우 탐색
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/stdc++.h>
// #define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
// using namespace std;
// using ll = long long;
// using ld = long double;
// using pii = pair<int, int>;
// const int sz = 1 << 17;
// ll cache[sz];
// ll board[100][100];
// int n;

// bool jump(int y, int x) {
//     // 기저 사례: 게임판 밖을 벗어난 경우
//     if (y >= n || x >= n) {
//         return false;
//     }
//     // 기저 사례: 마지막 칸에 도착한 경우
//     if (y == n - 1 && x == n - 1) {
//         return true;
//     }
//     int jumpSize = board[y][x];
//     return jump(y + jumpSize, x) || jump(y, x + jumpSize);
// }

// int main(void) {
//     ios::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     memset(cache, -1, sizeof(cache));
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> board[i][j];
//         }
//     }
//     if (jump(0, 0)) {
//         cout << "YES";
//     } else {
//         cout << "NO";
//     }
//     return 0;
// }