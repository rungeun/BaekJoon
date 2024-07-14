#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
using namespace std;

int Answer;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N[10], t;
    bool check;
    for (int i = 0; i < 10; i++) {
        cin >> t;
        N[i] = t % 42;
    }
    for(int i=0; i<10; i++){
        check=1;
        for(int j=i+1; j<10; j++){
            if(N[i]==N[j]){
                check=0;
            }
        }
        if(check){
            Answer++;
        }
    }
    cout << Answer << '\n';

    return 0;
}