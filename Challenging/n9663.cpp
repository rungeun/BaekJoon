#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
using namespace std;

int Answer = 0;
int k = 0;
int N;

// int v1[14][14];    // 체스 위치 기록용
//  bool visited1[27]={0};  // 우하향 방문 (-13 ~ 13)
//  bool visited2[27]={0};  // 우상향 방문 (0~26)
bool visited1[14][14] = {0};  // 방문
// bool visited2[14][14]={0};  // 우상향 방문
int v2[14][14];  // i-j 우하향 대각선
int v3[14][14];  // i+j 우상향 대각선

void backtracking(int x, int y) {
    // 종료
    if (k == N) {
        Answer++;
        return;
    }
    // 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited1[i][j] && v2[y][x] != v2[i][j]) {  //&& !visited2[i][j]
                visited1[i][j] = 1;
                for(int k=0; k<N; k++){
                    visited1[i][k]=1;
                }
                for(int k=0; k<N; k++){
                    visited1[k][j]=1;
                }
                if (x < N) {
                    backtracking(x + 1, y);
                } else {  // 다음행으로 이동
                    x = 0;
                    backtracking(x, y + 1);
                }
                visited1[i][j] = 0;
                
            }


        }
    }
}

void setarray() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            v2[i][j] = i - j;
            v3[i][j] = i + j;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;

    setarray();
    backtracking(0, 0);
    cout << Answer;
    return 0;
}

/*
//대각선 테스트 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << v2[i][j] << ' ';
            v2[i][j] = i + j;
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << v2[i][j] << ' ';
            v3[i][j] = i + j;
        }
        cout << '\n';
    }

    0  -1  -2  -3  -4  -5  -6  -7  -8  -9  -10 -11 -12 -13
    1   0  -1  -2  -3  -4  -5  -6  -7  -8  -9  -10 -11 -12
    2   1   0  -1  -2  -3  -4  -5  -6  -7  -8  -9  -10 -11
    3   2   1   0  -1  -2  -3  -4  -5  -6  -7  -8  -9  -10
    4   3   2   1   0  -1  -2  -3  -4  -5  -6  -7  -8  -9
    5   4   3   2   1   0  -1  -2  -3  -4  -5  -6  -7  -8
    6   5   4   3   2   1   0  -1  -2  -3  -4  -5  -6  -7
    7   6   5   4   3   2   1   0  -1  -2  -3  -4  -5  -6
    8   7   6   5   4   3   2   1   0  -1  -2  -3  -4  -5
    9   8   7   6   5   4   3   2   1   0  -1  -2  -3  -4
    10  9   8   7   6   5   4   3   2   1   0  -1  -2  -3
    11  10  9   8   7   6   5   4   3   2   1   0  -1  -2
    12  11  10  9   8   7   6   5   4   3   2   1   0  -1
    13  12  11  10  9   8   7   6   5   4   3   2   1   0

    0 1 2 3 4 5 6 7 8 9 10 11 12 13
    1 2 3 4 5 6 7 8 9 10 11 12 13 14
    2 3 4 5 6 7 8 9 10 11 12 13 14 15
    3 4 5 6 7 8 9 10 11 12 13 14 15 16
    4 5 6 7 8 9 10 11 12 13 14 15 16 17
    5 6 7 8 9 10 11 12 13 14 15 16 17 18
    6 7 8 9 10 11 12 13 14 15 16 17 18 19
    7 8 9 10 11 12 13 14 15 16 17 18 19 20
    8 9 10 11 12 13 14 15 16 17 18 19 20 21
    9 10 11 12 13 14 15 16 17 18 19 20 21 22
    10 11 12 13 14 15 16 17 18 19 20 21 22 23
    11 12 13 14 15 16 17 18 19 20 21 22 23 24
    12 13 14 15 16 17 18 19 20 21 22 23 24 25
    13 14 15 16 17 18 19 20 21 22 23 24 25 26

*/