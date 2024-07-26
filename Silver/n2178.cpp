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

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};
vector<vector<bool>> dis;  // 방문 기록 벡터

int bfs(int r, int c) {
    vector<vector<int>> distance(N, vector<int>(M, INF));  // 최단거리 기록 벡터
    queue<pii> q;                                          // 방문 예정 큐
    dis[r][c] = false;                                     // 방문 처리
    distance[r][c] = 0;                                    // 카운트 초기화
    q.emplace(r, c);                                       // q에 현재 위치를 넣음
    while (!q.empty()) {
        auto [cr, cc] = q.front();                                                          // q의 front값을 cr와cc에 넣음
        q.pop();                                                                            // pop
        FOR(k, 4) {                                                                         // 4방향 검사
            int nextr = cr + dr[k];                                                         // 다음 행
            int nextc = cc + dc[k];                                                         // 다음 열
            if (0 <= nextr && nextr < N && 0 <= nextc && nextc < M && dis[nextr][nextc]) {  // 다음 이동할 위치가 인덱스 초과가 아니면서 방문 가능할 경우
                dis[nextr][nextc] = false;                                                  // 방문 처리
                distance[nextr][nextc] = distance[cr][cc] + 1;                              // 이동 거리 추가
                q.emplace(nextr, nextc);                                                    // 큐에 다음 위치를 넣음
                if (nextr == N - 1 && nextc == M - 1) {                                     // 마지막 칸에 도착 했다면
                    return distance[nextr][nextc] + 1;                                      // 이동거리(최단거리) 반환
                }
            }
        }
    }
    return -1;
}

int solve() {
    int Answer = 0;
    cin >> N >> M;
    dis.resize(N, vector<bool>(M, true));  // 방문 기록 벡터
    string str;
    FOR(i, N) {
        cin >> str;
        FOR(j, M) {
            dis[i][j] = (str[j] == '1');  // 문제에서 1은 이동가능, 0은 이동 불가능 -> 1=미방문 , 0=방문
        }
    }
    Answer = bfs(0, 0);
    return Answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cout << solve() << '\n';
    return 0;
}