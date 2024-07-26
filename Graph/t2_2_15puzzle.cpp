#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr int sz = 1 << 17;
constexpr int INF = INT_MAX;

// 게임판의 상태를 표현한다.
class State {
    // 인접한 상태들의 목록을 반환한다.
    vector<State> getAdjacent() const;
    // map에 state를 넣기 위한 연산자
    bool operator<(const State& rhs) const;
    // 종료 상태와 비교하기 위한 연산자
    bool operator==(const State& rhs) const;
};

typedef map<State, int> StateMap;
// start에서 finish까지 가는 최단 경로의 길이를 반환한다.
int bfs(State s, State e) {
    // 예외: s == e;
    if (s == e) return 0;
    // 각 정점ㄲ
}


int solve() {
    int Answer = 0;
    int N;
    cin >> N;
    for (int _ = 0; _ < N; _++) {
    }

    return Answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    // int testCase;
    // cin >> testCase;
    // for (int _ = 0; _ < testCase; _++) {
    cout << solve();  //<< '\n';
    // }
    return 0;
}