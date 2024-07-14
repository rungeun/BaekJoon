#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n';
using namespace std;

int Answer;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    int X;
    string str;
    stack<int> stack;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        if (str == "push") {
            cin >> X;
            stack.push(X);
        } else if (str == "pop") {
            if (stack.size() == 0) {
                Answer = -1;
            } else {
                Answer = stack.top();
                stack.pop();
            }
            cout << Answer << '\n';
        } else if (str == "size") {
            Answer = stack.size();
            cout << Answer << '\n';
        } else if (str == "empty") {
            if (stack.size() == 0) {
                Answer = 1;
            } else {
                Answer = 0;
            }
            cout << Answer << '\n';
        } else if (str == "top") {
            if (stack.size() == 0) {
                Answer = -1;
            } else {
                Answer = stack.top();
            }
            cout << Answer << '\n';
        }
    }

    return 0;
}