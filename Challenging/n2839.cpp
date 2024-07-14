#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
const int sz = 1 << 17;
/*
1<<17 : 131,072
1<<20 : 1,048,576
1<<24 : 16,777,216
1<<27 : 134,217,728
1<<31 - 1: 2,147,483,647(int 자료형의 상한값)
1<<63 - 1 : 9,223,372,036,854,775,807(long long자료형의 상한값)
1<<64 - 1 : 18,446,744,073,709,551,615 (unsigned long long자료형의 상한값)
*/
int Answer;

int main(void) {
    unsigned long long a;
    a= 18446744073709551614;
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cout << a;
    return 0;
}