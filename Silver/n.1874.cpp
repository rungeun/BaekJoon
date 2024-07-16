#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int sz = 1 << 17;
int target[sz];

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    int cn = 1;
    stack<int> st;
    queue<char> que;
    cin >> N;
    for (int _ = 0; _ < N; _++) {
        cin >> target[_];
    }

    for (int i = 0; i < N; i++) {
        while (cn <= target[i]) {
            st.push(cn++);
            que.push('+');
        }
        if(st.top()==target[i]){
            st.pop();
            que.push('-');
        }
        else{
            cout<<"NO";
            return 0;
        }
    }

    while(!que.empty()){
        cout<<que.front()<<'\n';
        que.pop();
    }
    return 0;
}
