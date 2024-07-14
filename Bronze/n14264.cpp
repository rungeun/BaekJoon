#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
double Answer;
int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    double l,temp;
    cin>>l;
    temp = l*sqrt(3);
    Answer = (l*temp)/4;
        cout.precision(15);
    cout << fixed << Answer << endl;
    return 0;
}

