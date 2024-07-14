#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
using namespace std;

// 상수 sz는 2^17 (131072s)로 설정
const int sz = 1 << 17;
int a[sz], b[sz];     // 배열 a와 b 선언
int arr[2][sz << 1];  // 세그먼트 트리용 2차원 배열 arr 선언

// 세그먼트 트리 업데이트 함수
void update(bool x, int i, int val) {
    i += sz;          // 리프 노드 위치 설정
    arr[x][i] = val;  // 리프 노드 값 설정
    while (i > 1) {
        i >>= 1;                                              // 부모 노드로 이동
        arr[x][i] = max(arr[x][i << 1], arr[x][i << 1 | 1]);  // 부모 노드 갱신
    }
}

// 세그먼트 트리에서 구간 [s, e]의 최대값을 반환하는 쿼리 함수
int query(bool x, int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (e < ns || ne < s) return 0;               // 쿼리 범위가 노드 범위를 벗어나는 경우
    if (s <= ns && ne <= e) return arr[x][node];  // 노드 범위가 쿼리 범위 내에 있는 경우
    int mid = (ns + ne) >> 1;                     // 노드 범위의 중간 계산
    // 왼쪽 자식과 오른쪽 자식 쿼리 결과 중 최대값 반환
    return max(query(x, s, e, node << 1, ns, mid), query(x, s, e, node << 1 | 1, mid + 1, ne));
}

// 각 테스트 케이스를 해결하는 함수
void solve() {
    memset(arr, 0, sizeof(arr));                      // 세그먼트 트리 배열을 0으로 초기화
    int n, L;                                         // 변수 n은 배열의 크기, L은 제한값
    scanf("%d%d", &n, &L);                            // n과 L 입력 받기
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);  // 배열 a 입력 받기
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);  // 배열 b 입력 받기
    sort(a + 1, a + 1 + n);                           // 배열 a 정렬
    sort(b + 1, b + 1 + n);                           // 배열 b 정렬

    int ans = 0;  // 최대 차이값 저장 변수
    
    // 정렬된 배열에서 대응되는 요소의 차이를 계산
    for (int i = 1; i <= n; i++) {   // (-1인경우)
        if (abs(a[i] - b[i]) > L) {  // 차이가 L을 초과하면
            printf("-1\n");          // 불가능하므로 -1 출력
            return;
        }
        ans = max(ans, abs(a[i] - b[i]));  // 최대 차이값 갱신
        //TEST("ans1",ans);
        /*
        * a와b에 대해 같은 인덱스 번호의 차로 ans의 최대 값을 찾음(적절한 값을 찾은듯)
        */
    }

    // 세그먼트 트리 초기화
    for (int i = 1; i < n; i++) {            /* *세그먼트 트리의 첫번째 노드는 1인덱스 부터 시작 해야됨*/
        update(0, i, abs(a[i] - b[i + 1]));  // 첫 번째 세그먼트 트리 갱신
        update(1, i, abs(a[i + 1] - b[i]));  // 두 번째 세그먼트 트리 갱신
    }

    int A = 1, B = 1;  // 포인터 A와 B 초기화
    // 포인터 A와 B가 배열 범위 내에 있을 때까지 반복
    while (1) {
        B++;
        if (A > n || B > n) break;                                   // 포인터가 배열 범위를 벗어나면 종료
        while (query(1, A, B - 1) > L || abs(a[A] - b[B]) > L) A++;  // 조건을 만족할 때까지 A 증가
        ans = max({ans, query(1, A, B - 1), abs(a[A] - b[B])});      // 최대값 갱신
    }

    A = 1, B = 1;  // 포인터 초기화
    // 포인터 A와 B가 배열 범위 내에 있을 때까지 반복
    while (1) {
        A++;
        if (A > n || B > n) break;                                   // 포인터가 배열 범위를 벗어나면 종료
        while (query(0, B, A - 1) > L || abs(a[A] - b[B]) > L) B++;  // 조건을 만족할 때까지 B 증가
        ans = max({ans, query(0, B, A - 1), abs(a[A] - b[B])});      // 최대값 갱신
    }

    printf("%d\n", ans);  // 최종 결과 출력
}

int main() {
    setbuf(stdout, NULL);            // 표준 출력 버퍼링 해제
    int tc;                          // 테스트 케이스 수
    scanf("%d", &tc);                // 테스트 케이스 수 입력
    for (int i = 1; i <= tc; i++) {  // 각 테스트 케이스에 대해
        printf("Case #%d\n", i);     // 케이스 번호 출력
        solve();                     // 문제 해결 함수 호출
    }
    return 0;
}
