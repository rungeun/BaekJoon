#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#if !(defined ONLINE_JUDGE || defined CODE_GROUND)
#define TEST(X, Y) cerr << (X) << ": " << (Y) << '\n'
#else
#define TEST(x, Y)
#endif
#define ALL(x) x.begin(), x.end()
#define FOR(y, x) for (int(y) = 0; (y) < (x); (y)++)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr int sz = 1 << 17;
constexpr int INF = 0x7fffffff;
int N, M;

void solve() {
    cin >> N >> M;
    string name;
    char star;
    set<int> cnt;
    vector<int> vec1;
    vector<string> vec2;
    FOR(_, N) {
        int start = -1;
        int end = -1;
        bool flag = true;
        int Answer = 0;

        FOR(i, M) {
            cin >> star;
            if (star == '.' && flag) {
                start = i;
                flag = false;
            }

            if (star == '*' && !flag) {
                end = i;
                Answer = max(Answer, end - start);
                flag = true;
            }
        }
        if (star == '.' && !flag) {
            end = M;
            Answer = max(Answer, end - start);
        }
        cnt.insert(Answer);

        cin >> name;
        vec1.push_back(Answer);
        vec2.push_back(name);
    }

        cout << cnt.size() << '\n';

    FOR(_, N) { cout << vec1[_] << ' ' << vec2[_] << '\n'; }
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();  
    return 0;
}