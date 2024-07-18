#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const ll MOD = 1e9 + 7;
const int sz = 1 << 12;
const int INF = INT_MAX;

int smap[sz];
int cmap[sz];

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M, B;
    int h = INF, time = INF, cH, ctime;  // 가장 작은 h높이,time연산시간 //현재 h높이,cTime연산시간

    cin >> N >> M >> B;
    for (int _ = 0; _ < N * M; _++) {  // 2차원 배열일 필요가 없다, 1차원 배열에서 모든 높이를 맞춘다면 정답 조건에 부합하다
        cin >> smap[_];
    }
    sort(smap, smap + N * M);

    int min_height = smap[0];
    int max_height = smap[N * M - 1];

    for (int target = min_height; target <= max_height; ++target) {
        ctime = 0;
        int inventory = B;
        for (int i = 0; i < N * M; ++i) {
            if (smap[i] > target) {
                ctime += 2 * (smap[i] - target);
                inventory += (smap[i] - target);
            } else if (smap[i] < target) {
                ctime += (target - smap[i]);
                inventory -= (target - smap[i]);
            }
        }
        if (inventory >= 0) {
            if (ctime < time || (ctime == time && target > h)) {
                time = ctime;
                h = target;
            }
        }
    }

    cout << time << " " << h << '\n';
    return 0;
}
