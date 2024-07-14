#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 50 + 1;

int main(void) {
    int n;
    string ch;
    string ch_result;
    cin >> n;
    
    cin>>ch_result;

    for (int i = 0; i < n-1; i++) {
        
        cin >>ch;
        for(int k=0; k<ch.length(); k++){
            if(ch_result[k] != ch[k]){
                ch_result[k]= '?';
            }
        }
    }

    cout<<ch_result;
    
    return 0;
}