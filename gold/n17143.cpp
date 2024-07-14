// #include <iostream>
// using namespace std;

// class Shark {
//    private:
//     int r, c, s, d, z, object_count;
//     int y, yr;

//    public:
//     Shark();
//     ~Shark();
//     /** (r, c)는 위치, s는 속력, d는 이동 방향, z는 크기를 초기화하는 함수 */
//     void SetInfo(int r, int c, int s, int d, int z, int object_count) {
//         this->r = r;
//         this->c = c;
//         this->s = s;
//         this->d = d;
//         this->z = z;
//         this->object_count = object_count;
//     }
//     int GetR() { return r; }
//     int GetC() { return c; }
//     int GetZ() { return z; }
//     int GetS() { return s; }
//     int GetD() { return d; }
//     int GetObjectCount() { return object_count; }
//     void Move(int R, int C) {
//         object_count++;
//         y = (s % ((C - 1) * 2));
//         yr = (s % ((R - 1) * 2));

//         switch (d) {
//             case 1:                           // 상 //BUG: 행이 1개 일경우 작동X
//                 cout << "상 실행됨" << endl;  // REMOVE
//                 if (s == 0) break;

//                 if (s < r || yr < r) {  // FIXME: 조건 수정해야됨 (일단 정상 작동)
//                     r -= yr;            // 좌측으로 가는 경우
//                     cout << r << endl;  // REMOVE
//                 } else {
//                     cout << "else문 실행됨" << endl;  // REMOVE
//                     r = yr + r - ((r - 1) * 2);
//                     d = 2;  // 방향을 하측으로 바꿈
//                 }
//                 break;
//             case 2:                           // 하 //BUG: 행이 1개 일경우 작동X
//                 cout << "하 실행됨" << endl;  // REMOVE
//                 if (s == 0) break;
//                 if ((r + yr) <= R) {
//                     r += yr;  // 우측으로 가는 경우
//                 } else {
//                     r = R - (yr - (R - r));  // 좌측으로 가는 경우
//                     d = 1;                   // 방향을 상측으로 바꿈
//                 }
//                 break;
//             case 3:                           // 우
//                 cout << "우 실행됨" << endl;  // REMOVE
//                 if (s == 0) break;
//                 if ((c + y) <= C) {
//                     c += y;  // 우측으로 가는 경우
//                 } else {
//                     c = C - (y - (C - c));  // 좌측으로 가는 경우
//                     d = 4;                  // 방향을 좌측으로 바꿈
//                 }
//                 break;
//             case 4:                           // 좌
//                 cout << "좌 실행됨" << endl;  // REMOVE
//                 if (s == 0) break;
//                 if (s < c || y < c) {   // FIXME: 조건 수정해야됨 (일단 정상 작동)
//                     c -= y;             // 좌측으로 가는 경우
//                     cout << c << endl;  // REMOVE
//                 } else {
//                     cout << "else문 실행됨" << endl;  // REMOVE
//                     c = y + c - ((c - 1) * 2);
//                     d = 3;
//                 }
//                 break;
//         }
//     }
//     void Delete() {
//         r = -1;
//         c = -1;
//         s = -1;
//         d = -1;
//         z = -1;
//     }
// };

// Shark::Shark(/* args */) {}

// Shark::~Shark() {}

// int main(void) {
//     int R, C, M;
//     int r, c, s, d, z;
//     int main_count = 0;
//     int result = 0;
//     int result_i = 1;
//     cin >> R >> C >> M;

//     Shark map[101][101];  // Shark 객체를 위한 맵 초기화
//     // for (int i = 1; i <= R; ++i) {
//     //     for (int j = 1; j <= C; ++j) {
//     //         map[i][j].SetInfo(-1, -1, -1, -1, -1);  // 빈칸 초기화
//     //     }
//     // }
//     for (int i = 0; i < M; i++) {
//         cin >> r >> c >> s >> d >> z;
//         map[r][c].SetInfo(r, c, s, d, z, 0);  // 맵에 상어 객체 설정
//     }

//     // REMOVE: 상어 위치 테스트 출력
//     for (int i = 1; i <= R; i++) {
//         for (int j = 1; j <= C; j++) {
//             if (map[i][j].GetZ() > 0) {
//                 cout << map[i][j].GetZ() << ' ';  // 상어가 있는 위치에 크기 출력
//             } else {
//                 cout << "0 ";  // 상어가 없는 위치에 0 출력
//             }
//         }
//         cout << endl;
//     }

//     int testCount = 0;
//     while (testCount < C) {
//         for (int i = 1; i <= R; i++) {
//             for (int j = 1; j <= C; j++) {
//                 if (map[i][j].GetZ() > 0 && main_count == map[i][j].GetObjectCount()) {
//                     cout << i << ' ' << j << "Move 실행" << map[i][j].GetObjectCount() << endl;  // REMOVE
//                     map[i][j].Move(R, C);                                                        // object_count++;

//                     if (map[map[i][j].GetR()][map[i][j].GetC()].GetZ() < map[i][j].GetZ()) {
//                         map[map[i][j].GetR()][map[i][j].GetC()].SetInfo(map[i][j].GetR(), map[i][j].GetC(), map[i][j].GetS(), map[i][j].GetD(), map[i][j].GetZ(),
//                                                                         map[i][j].GetObjectCount());  // 새로운 맵에 상어 객체 설정
//                     }
//                     if (map[i][j].GetS() != 0) {
//                         map[i][j].Delete();
//                     }
//                 }
//             }
//         }

//         main_count++;

//         // REMOVE: 상어 위치 테스트 출력
//         cout << "------------------------" << endl;
//         for (int i = 1; i <= R; i++) {
//             for (int j = 1; j <= C; j++) {
//                 if (map[i][j].GetZ() > 0) {
//                     cout << map[i][j].GetZ() << ' ';  // 상어가 있는 위치에 크기 출력
//                 } else {
//                     cout << "0 ";  // 상어가 없는 위치에 0 출력
//                 }
//             }
//             cout << endl;
//         }

//         result_i++;
//         testCount++;
//     }
//     cout << result << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

class Shark {
   private:
    int r, c, s, d, z, object_count;
    int y, yr;

   public:
    Shark();
    ~Shark();
    /** (r, c)는 위치, s는 속력, d는 이동 방향, z는 크기를 초기화하는 함수 */
    void SetInfo(int r, int c, int s, int d, int z, int object_count) {
        this->r = r;
        this->c = c;
        this->s = s;
        this->d = d;
        this->z = z;
        this->object_count = object_count;
    }
    int GetR() { return r; }
    int GetC() { return c; }
    int GetZ() { return z; }
    int GetS() { return s; }
    int GetD() { return d; }
    int GetObjectCount() { return object_count; }
    void Move(int R, int C) {
        object_count++;
        y = (s % ((C - 1) * 2));
        yr = (s % ((R - 1) * 2));

        switch (d) {
            case 1:                           // 상

                if (s == 0) break;

                if (s < r || yr < r) {
                    r -= yr;            // 좌측으로 가는 경우

                } else {

                    r = yr + r - ((r - 1) * 2);
                    d = 2;  // 방향을 하측으로 바꿈
                }
                break;
            case 2:                           // 하

                if (s == 0) break;
                if ((r + yr) <= R) {
                    r += yr;  // 우측으로 가는 경우
                } else {
                    r = R - (yr - (R - r));  // 좌측으로 가는 경우
                    d = 1;                   // 방향을 상측으로 바꿈
                }
                break;
            case 3:                           // 우

                if (s == 0) break;
                if ((c + y) <= C) {
                    c += y;  // 우측으로 가는 경우
                } else {
                    c = C - (y - (C - c));  // 좌측으로 가는 경우
                    d = 4;                  // 방향을 좌측으로 바꿈
                }   
                break;
            case 4:                           // 좌

                if (s == 0) break;
                if (s < c || y < c) {
                    c -= y;             // 좌측으로 가는 경우

                } else {

                    c = y + c - ((c - 1) * 2);
                    d = 3;
                }
                break;
        }
    }
    void Delete() {
        r = -1;
        c = -1;
        s = -1;
        d = -1;
        z = -1;
    }
};

Shark::Shark(/* args */) {}

Shark::~Shark() {}

int main(void) {
    int R, C, M;
    int r, c, s, d, z;
    int main_count = 0;
    int result = 0;
    int result_i = 1;
    cin >> R >> C >> M;

    Shark map[101][101];  // Shark 객체를 위한 맵 초기화
    // for (int i = 1; i <= R; ++i) {
    //     for (int j = 1; j <= C; ++j) {
    //         map[i][j].SetInfo(-1, -1, -1, -1, -1);  // 빈칸 초기화
    //     }
    // }
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        map[r][c].SetInfo(r, c, s, d, z, 0);  // 맵에 상어 객체 설정
    }

    int testCount = 0;
    while (testCount < C) {
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (map[i][j].GetZ() > 0 && main_count == map[i][j].GetObjectCount()) {
                    map[i][j].Move(R, C);                                                        // object_count++;

                    if (map[map[i][j].GetR()][map[i][j].GetC()].GetZ() < map[i][j].GetZ()) {
                        map[map[i][j].GetR()][map[i][j].GetC()].SetInfo(map[i][j].GetR(), map[i][j].GetC(), map[i][j].GetS(), map[i][j].GetD(), map[i][j].GetZ(),
                                                                        map[i][j].GetObjectCount());  // 새로운 맵에 상어 객체 설정
                    }
                    if (map[i][j].GetS() != 0) {
                        map[i][j].Delete();
                    }
                }
            }
        }

        main_count++;

        for (int j = 1; j <= R; j++) {
            if (map[result_i][j].GetZ() > 0) {
                result += map[result_i][j].GetZ();
                map[result_i][j].Delete();
                break;
            }
        }

        result_i++;
        testCount++;
    }
    cout << result;
    return 0;
}




// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class Shark {
// public:
//     int r, c, s, d, z;

//     Shark(int r = -1, int c = -1, int s = 0, int d = 0, int z = 0)
//         : r(r), c(c), s(s), d(d), z(z) {}

//     void SetInfo(int r, int c, int s, int d, int z) {
//         this->r = r;
//         this->c = c;
//         this->s = s;
//         this->d = d;
//         this->z = z;
//     }

//     int GetR() { return r; }
//     int GetC() { return c; }
//     int GetS() { return s; }
//     int GetD() { return d; }
//     int GetZ() { return z; }

//     void Move(int R, int C) {
//         int moveCount;
//         if (d == 1 || d == 2) {  // 상하
//             moveCount = s % (2 * (R - 1));
//             for (int i = 0; i < moveCount; i++) {
//                 if (d == 1 && r == 1) d = 2;  // 상 -> 하
//                 else if (d == 2 && r == R) d = 1;  // 하 -> 상
//                 r += (d == 1) ? -1 : 1;
//             }
//         } else if (d == 3 || d == 4) {  // 좌우
//             moveCount = s % (2 * (C - 1));
//             for (int i = 0; i < moveCount; i++) {
//                 if (d == 3 && c == C) d = 4;  // 우 -> 좌
//                 else if (d == 4 && c == 1) d = 3;  // 좌 -> 우
//                 c += (d == 3) ? 1 : -1;
//             }
//         }
//     }

//     void Delete() {
//         r = -1;
//         c = -1;
//         s = 0;
//         d = 0;
//         z = 0;
//     }
// };

// int main() {
//     int R, C, M;
//     cin >> R >> C >> M;

//     Shark map[101][101];
//     for (int i = 0; i < M; i++) {
//         int r, c, s, d, z;
//         cin >> r >> c >> s >> d >> z;
//         map[r][c].SetInfo(r, c, s, d, z);
//     }

//     int result = 0;
//     for (int fisher = 1; fisher <= C; ++fisher) {
//         // 낚시왕이 상어를 잡는다.
//         for (int row = 1; row <= R; ++row) {
//             if (map[row][fisher].GetZ() > 0) {
//                 result += map[row][fisher].GetZ();
//                 map[row][fisher].Delete();
//                 break;
//             }
//         }

//         // 상어가 이동한다.
//         Shark newMap[101][101];
//         for (int i = 1; i <= R; ++i) {
//             for (int j = 1; j <= C; ++j) {
//                 if (map[i][j].GetZ() > 0) {
//                     map[i][j].Move(R, C);
//                     int nr = map[i][j].GetR();
//                     int nc = map[i][j].GetC();
//                     if (newMap[nr][nc].GetZ() == 0 || newMap[nr][nc].GetZ() < map[i][j].GetZ()) {
//                         newMap[nr][nc] = map[i][j];
//                     }
//                 }
//             }
//         }

//         // 새로운 맵으로 갱신
//         for (int i = 1; i <= R; ++i) {
//             for (int j = 1; j <= C; ++j) {
//                 map[i][j] = newMap[i][j];
//             }
//         }
//     }

//     cout << result << endl;
//     return 0;
// }
