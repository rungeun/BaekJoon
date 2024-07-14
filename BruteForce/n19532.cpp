#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
using namespace std;

class BruteForce {
   public:
    int a, b, c, d, e, f;
    int x, y;
    BruteForce(int a, int b, int c, int d, int e, int f) {
        bool check = true;
        for (int i = -999; i < 999 +1 && check; i++) {
            for (int j = -999; j < 999 +1 && check; j++) {
                if ((a * i + b * j) == c && (d * i + e * j) == f) {
                    x=i;
                    y=j;
                    check = false;
                }
            }
        }
    }
};

int main(void) {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    BruteForce bf(a, b, c, d, e, f);
    cout << bf.x << ' ' << bf.y;
    return 0;
}