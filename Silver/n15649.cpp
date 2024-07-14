#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
using namespace std;

int N, M;
int arr[8];
bool v[8]={0};

void dfs(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) cout << arr[i] + 1 << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!v[i]) {
            arr[k] = i;
            v[i] = 1;
            dfs(k + 1);
            v[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    dfs(0);
}

// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/stdc++.h>
// #define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
// using namespace std;

// vector<vector<int>> Answer;  // 정답을 저장할 배열
// int v[9];                    // 중복확인을 위한 visited 배열
// int N;                       // 전역 변수로 선언하여 dfs 함수에서도 접근 가능하게 함

// void dfs(int n, vector<int> &arr, int M) {
//     // 종료조건(n에 관련) 처리+정답처리
//     if (n == M) {
//         Answer.push_back(arr);
//         return;
//     }

//     // 하부 단계(함수) 호출
//     for (int i = 1; i < N + 1; i++) {
//         if (v[i] == 0) {  // 선택하지 않은 숫자인 경우 추가
//             v[i] = 1;
//             arr.push_back(i);
//             dfs(n + 1, arr, M);
//             arr.pop_back();
//             v[i] = 0;
//         }
//     }
// }

// int main(void) {
//     int M;

//     cin >> N >> M;
//     vector<int> vec;
//     dfs(0, vec, M);
//     for (const auto &ans : Answer) {
//         for (int num : ans) {
//             cout << num << " ";
//         }
//         cout << '\n';
//     }
//     return 0;
// }

// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/stdc++.h>
// #define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
// using namespace std;

// vector<int> Answer;  // 정답을 저장할 배열
// int v[9];            // 중복확인을 위한 visited배열

// int dfs(int n, vector<int> &arr, int M) {
//     // 종료조건(n에 관련) 처리+정답처리
//     if (n == M) {
//         Answer.push_back(arr);
//         return;
//     }

//     // 하부 단계(함수) 호출
//     for (int i = 1; i < N + 1; i++) {
//         if (v[i] == 0) {  // 선택하지 않은 숫자인 경우 추가
//             v[i] = 1;
//             dfs(n + 1, arr + [i]);
//             v[i] = 0;
//         }
//     }
// }

// int main(void) {
//     int N, M;

//     cin >> N >> M;
//     vector<int> vec;
//     dfs(0, vec, M);
//     for (int i = 0; i < N; i++) {
//         cout << Answer[i];
//     }
//     return 0;
// }

/*
백트랙킹: 가능한 모든 경우 실행 -> 정답찾기
n: 선택된 숫자 개수(길이)
길이 M짜리 수열

*/