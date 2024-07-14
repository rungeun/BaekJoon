#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 최대 차이를 찾는 함수
int maxDiff(vector<int>& A, vector<int>& B, int M) {
    int max_diff = -1;
    
    // 모든 가능한 조합을 조사하여 절댓값 차이를 계산
    for (int a : A) {
        for (int b : B) {
            int diff = abs(a - b);
            if (diff <= M) {
                max_diff = max(max_diff, diff);
            }
        }
    }
    
    // 모든 차이가 M보다 큰 경우
    if (max_diff == -1) {
        return -1;
    }
    
    return max_diff;
}


int main() {
    // 예제 데이터
    vector<int> A1 = {10, 20, 30, 40, 50};
    vector<int> B1 = {60, 50, 40, 30, 20};
    int M1 = 5;

    vector<int> A2 = {10, 20, 30, 40, 50};
    vector<int> B2 = {50, 40, 30, 20, 10};
    int M2 = 5;

    vector<int> A3 = {1, 2, 5, 10, 8, 9, 9, 12, 13, 13};
    vector<int> B3 = {1, 1, 4, 5, 7, 9, 11, 9, 13, 13};
    int M3 = 13;

    vector<int> A4 = {10, 20, 30, 40, 50};
    vector<int> B4 = {10, 20, 30, 40, 50};
    int M4 = 38;

    vector<int> A5 = {10, 20, 30, 40, 50};
    vector<int> B5 = {10, 20, 30, 2, 50};
    int M5 = 38;

    vector<int> A6 = {1000000000, 1, 2, 3, 4};
    vector<int> B6 = {1000000000, 1, 2, 3, 4};
    int M6 = 1000000000;

    cout << maxDiff(A1, B1, M1) << endl;
    cout << maxDiff(A2, B2, M2) << endl;
    cout << maxDiff(A3, B3, M3) << endl;
    cout << maxDiff(A4, B4, M4) << endl;
    cout << maxDiff(A5, B5, M5) << endl;
    cout << maxDiff(A6, B6, M6) << endl;

    return 0;
}
