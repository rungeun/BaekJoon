#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
#define ABSOLUTE(X) ((X > 0) ? (X) : ((-1) * X))
using namespace std;

long double Answer;


int main(void) {
    int N;
    double x[10000] = {0}, y[10000] = {0};
    long double cal = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    int j = N - 1;
    for (int i = 0; i < N; i++) {
        cal += (x[j] + x[i]) * (y[j] - y[i]);
        j=i;
    }
    cal = ABSOLUTE(cal);
    Answer += cal / 2;

    cout << fixed;
    cout.precision(1);
    cout << Answer;
    return 0;
}

// int main(void) {
//     int N;
//     double x[10000] = {0}, y[10000] = {0};
//     long double cal;
//     cin >> N;
//     for (int i = 0; i < N; i++) {
//         cin >> x[i] >> y[i];
//     }
// //오목한 다각형일 경우 아래식은 사용할 수 없다
//     for (int i = 0; i < N-2; i++) {
//         cal=(x[0]*y[i+1]+x[i+1]*y[i+2]+x[i+2]*y[0])-(x[0]*y[i+2]+x[i+1]*y[0]+x[i+2]*y[i+1]);
//         cal=ABSOLUTE(cal);
//         Answer+=cal/2;
//     }
//     cout<<fixed;
//     cout.precision(1);
//     cout << Answer;
//     return 0;
// }
