#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
string Answer;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    if (a.size() < b.size()) {
        Answer = "no";
    } else {
        Answer = "go";  
    }
    cout << Answer;
    return 0;
}