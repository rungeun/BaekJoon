#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
using namespace std;

class BruteForce {
   public:
    int result = 64; 

    BruteForce(bool board[50][50], int N, int M) {
        for (int y = 0; y <= N - 8; y++) {
            for (int x = 0; x <= M - 8; x++) {
                calculateMinimumRepaint(board, y, x);
            }
        }
    }

    void calculateMinimumRepaint(bool board[50][50], int startY, int startX) {
        int count1 = 0, count2 = 0;
        bool firstColor = true; 
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[startY + i][startX + j] != firstColor) {
                    count1++;
                }
                if (board[startY + i][startX + j] != !firstColor) {
                    count2++;
                }
                firstColor = !firstColor;
            }
            firstColor = !firstColor;
        }
        result = min(result, min(count1, count2));
    }
};

int main(void) {
    int N, M;
    char in;
    bool board[50][50] = {false}; // B == true, W == false
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> in;
            board[i][j] = (in == 'B');
        }
    }

    BruteForce bf(board, N, M);
    cout << bf.result;
    return 0;
}