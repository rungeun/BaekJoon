#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;

unordered_map<int, int> cp;
vector<int> sotredA;
int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> a(N);

    for (int _ = 0; _ < N; _++) {
        cin >> a[_];
        sotredA.push_back(a[_]);
    }
    sort(sotredA.begin(), sotredA.end());
    sotredA.erase(unique(sotredA.begin(), sotredA.end()), sotredA.end());  //*중복제거

    for (int _ = 0; _ < sotredA.size(); _++) {
        cp[sotredA[_]] = _;
    }

    for (int _ = 0; _ < N; _++) {
        cout << cp[a[_]] << ' ';
    }

    return 0;
}
