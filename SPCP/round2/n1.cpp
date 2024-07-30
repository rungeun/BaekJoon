#include <cmath>
#include <iostream>
#include <vector>
#define ONLINE_JUDGE ;
#if !(defined ONLINE_JUDGE)
#define TEST(X, Y) cerr << (X) << ": " << (Y) << '\n'
#else
#define TEST(x, Y)
#endif
using namespace std;
using ll = long long;

ll solve() {
    ll N, S, E;
    ll sCnt = 0;
    ll eCnt = 0;
    ll zeroCnt = 0;
    // ll oneCnt = 2;
    int start = -1, end = -1;
    bool ck = true;
    int x;
    int what = -1;
    cin >> N >> S >> E;
    for (ll _ = 0; _ < N; _++) {
        cin >> x;

        if (x == 1 && !ck) {
            end = _;
            TEST("start", start);
            TEST("end", end);
            zeroCnt = zeroCnt - 1;
            TEST("ZEROCNT", zeroCnt);
            TEST("ONECNT", oneCnt);
            ll s = zeroCnt * S;
            ll e = 2 * E;
            TEST("ZERO", s);
            TEST("ONE", e);
            if (s < e) {
                sCnt += end - start - 1;
            } else {
                eCnt += 1;
            }
            zeroCnt = 0;
            what = end;
            start = end;
        }

        if (x == 1 && ck) {
            start = _;
            ck = false;
            zeroCnt = 0;
        }

        zeroCnt++;
    }
    TEST("sCnt", sCnt);
    TEST("eCnt", eCnt);
    if (start == -1 && end == -1) {
        return 0;
    }
    return sCnt * S + eCnt * E;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, test_case;
    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {
        TEST("TC TC TC TC", T);
        cout << "Case #" << test_case + 1 << endl;
        cout << solve() << endl;
    }
    return 0;
}

// #include <cmath>
// #include <iostream>
// #include <vector>
// #if !(defined ONLINE_JUDGE || defined CODE_GROUND)
// #define TEST(X, Y) cerr << (X) << ": " << (Y) << '\n'
// #else
// #define TEST(x, Y)
// #endif
// constexpr int INF = 0x7fffffff;
// constexpr int sz = 300'001;
// using namespace std;
// int N, S, E;  // S= 0->1 , E= 1->0
// int Answer;

// int solve() {
//     int arr[sz];
//     vector<int> VE;
//     vector<int> VS;
//     int start = -1, end = -1;
//     bool ck = true;
//     int zeroCnt;  // 1~{0..}~1집합을 찾았다면 1은 2개로 고정임
//     int oneCnt = 2;

//     cin >> N >> S >> E;
//     for (int _ = 0; _ < N; _++) {
//         cin >> arr[_];
//     }

//     for (int i = 0; i < N; i++) {
//         if (arr[i] == 1 && !ck) {
//             end = i;
//             TEST("start", start);
//             TEST("end", end);

//             // [ 여기서 부분 집합 계산 ]
//             zeroCnt = zeroCnt - 1;  // 처음 1의 개수도 들어 갔으므로 1개 빼줘야함
//             // 0과 1의 비용 계산
//             TEST("ZEROCNT", zeroCnt);
//             TEST("ONECNT", oneCnt);
//             int s = zeroCnt * S;  // 0교환의 총 비용
//             int e = oneCnt * E;   // 1교환의 총 비용
//             TEST("ZERO", s);
//             TEST("ONE", e);
//             // 비용이 작은 쪽의 인덱스를 벡터에 넣어줌
//             if (s < e) {
//                 for (int k = start + 1; k < end; k++) {
//                     TEST("PUSH S", k);
//                     VS.push_back(k);
//                 }
//             } else {
//                 VE.push_back(end);
//             }
//             zeroCnt = 0;  // 0의 개수 초기화
//             start = end;  // 다음 부분 집합의 시작 지점
//         }

//         // 부분 집합 start, end 찾기
//         if (arr[i] == 1 && ck) {
//             start = i;
//             ck = false;   // end 찾기 허용
//             zeroCnt = 0;  // 0의 개수 초기화
//         }

//         zeroCnt++;  // 0의 개수 카운팅
//     }

//     TEST("VS", VS.size());
//     TEST("VE", VE.size());
//     for (int i = 0; i < VS.size(); i++) {
//         TEST("Vsv", VS[i]);
//     }
//     for (int i = 0; i < VE.size(); i++) {
//         TEST("Vev", VE[i]);
//     }

//     // 기저조건 모두 1인 경우

//     // 기저조건: 1이 0개인 경우
//     if (start == -1 && end == -1) {
//         return 0;
//     }

//     return VS.size() * S + VE.size() * E;
// }

// int main(void) {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     int T, test_case;
//     cin >> T;
//     for (test_case = 0; test_case < T; test_case++) {
//         TEST("TC TC TC TC", test_case + 1);
//         cout << "Case #" << test_case + 1 << endl;
//         cout << solve() << endl;
//     }

//     return 0;
// }

// /*
// 1 1 0 1
// 1 1 1 1
// 1 1 0 0

// 1 1 0 1
// 1 1 1 1

// 0 1 0 0 0 1 0 1
// 0 1 1 1 1 1 1 1 (총비용 =4)

// 0 0 0 0 0 0 0 1 0 1
// S=1 -> 1 * 8 = 8
// E=10-> 10* 2 = 20
// 1 1 1 1 1 1 1 1 1 1

// 0 0 0 0 0 0 0 1 0 1 (총비용 =1)
// S=1 -> 1 * 8 = 8
// E=2->  2 * 2 = 4

// 0 0 0 0 1 0 0 1 0 1
// 0 0 0 0 1 1 1 1 1 1 (총비용 =3)
// 0 0 0 0 0 0 0 1 1 1 (총비용= 3)
// S=1 -> 1 * 7 = 7
// E=2->  2 * 3 = 6

// 1 0 0 0 1
// S=1 -> 1 * 3 = 3
// E=2->  2 * 2 = 4
// 0 0 0 0 1 || 1 0 0 0 0(비용 =2)

// 탐색 범위 0~{ }~0 , 1~{ }~1
// ->  1~{ }~1를 기본 베이스로 출발 1~{ }~1 사이의 0 개수 탐색
// 1~{ }~1의 { }와 1을 지우는 것중 최솟값이 정답 -> 반복
// (TC4)
// 1 0 0 1 0 1 다음과 같을 때
// 1 {0 0 1 0} 1을 비교 내부에서 0->1비용이 더 적기 때문에 내부 0을 1로 변경

// (TC3) (0만 바꿔야 이득인 TC이다)
// 0 1 0 0 0 1 0 1
// 0 1 { 0 0 0 1 0} 1
// 내부: 0->1 = 4
// 외부: 1->0 = 2000000

// (해당 작업을 0~{}~0도 해야 될지는 추후 검사)

// 그러면 (비용*개수)가 적은 걸 바꿔 버리면?

// */

// /*
// ->  1~{ }~1를 기본 베이스로 출발 1~{ }~1 사이의 0 개수 탐색
// 1~{ }~1의 { }와 1을 지우는 것중 최솟값이 정답 -> 반복
// */

// /*
// TC1
// 4
// 4 1 1
// 1 1 0 1
// 4 1 2
// 1 1 0 1
// 8 1 1000000
// 0 1 0 0 0 1 0 1
// 10 1 2
// 0 0 0 0 1 0 0 1 0 1

// Case #1
// 1
// Case #2
// 1
// Case #3
// 4
// Case #4
// 3

// TC2
// 4
// 4 1 1
// 1 1 0 1
// 4 2 1
// 1 1 0 1
// 8 1000000 1
// 0 1 0 0 0 1 0 1
// 10 2 1
// 0 0 0 0 1 0 0 1 0 1

// Case #1
// 1
// Case #2
// 1
// Case #3
// 2
// Case #4
// 2

// TC3
// 1
// 13 1 2
// 0 0 1 0 0 1 1 1 0 0 1 1 0 0

// 4

// TC4
// 2
// 4 1 1
// 0 0 0 0
// 4 1 1
// 1 1 1 1
// Case #1
// 0
// Case #1
// 0

// */