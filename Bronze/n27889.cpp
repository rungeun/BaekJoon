#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    string str;
    cin >> str;
    if (str == "NLCS") {
        cout << "North London Collegiate School";
    } else if (str == "BHA") {
        cout << "Branksome Hall Asia";
    } else if (str == "KIS") {
        cout << "Korea International School";
    } else if (str == "SJA") {
        cout << "St. Johnsbury Academy";
    }
    return 0;
}