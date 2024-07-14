#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
#define MAX 2
using namespace std;

int Answer;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int A, B, C;
    string Astr, Bstr;

    // 수로 생각했을 때
    cin >> A >> B >> C;
    Answer = A + B - C;
    cout << Answer << '\n';

    // 문자열로 생각했을
    // A + B
    Astr = to_string(A);
    Bstr = to_string(B);
    Astr = Astr + Bstr;
    A = stoi(Astr);
    Answer = A - C;
    cout << Answer;
    return 0;
}