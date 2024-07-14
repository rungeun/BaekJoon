#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    double a, b, c, d;
    cin >> a >> b >> c;
    d = (a * c) / b;

    printf("%lf", d);

    return 0;
}