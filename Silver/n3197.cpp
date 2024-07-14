#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    int R, C, T;
    int lCheck = 0;
    cin >> R >> C;
    vector<vector<int>> matrix(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> T;
            if (T == 'L') { //
                lCheck = 1;
            }
            if (lCheck == 0) {  //백조를 만나기 전까지 전부 0으로 초기화(계산x 구역)
                matrix[i][j] = 0;  
            }
            else if(T == '.') {  // 물
                matrix[i][j] = 1;
            }
            else if(T == 'X') {  // 얼음
                matrix[i][j] = 2;
            }
            else if(T == 'L') {  // 백조
                matrix[i][j] = 3;
            }
        }
    }

    for (const auto &row : matrix) {    //테스트 출력
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}

//폐기: 예외가 있어서 안됨