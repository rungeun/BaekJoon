#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;

int Answer = 0;
map<string, int> m;
vector<string> vec;
int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    string str;
    int N, M;
    cin >> N >> M;

    for (int _ = 0; _ < N + M; _++) {
        cin >> str;
        if (m[str] == 1) {
            Answer++;
            vec.push_back(str);

        } else {
            m[str]++;
        }
    }

    sort(vec.begin(), vec.end());
    cout << Answer << '\n';
    for (const string& s : vec) {
        cout << s << '\n';
    }
    return 0;
}