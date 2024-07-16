#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
string Answer;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    string input;
    while (true) {
        getline(cin, input);
        if (input == ".") {
            break;
        }

        stack<char> st;
        Answer = "yes";

        for (char ch : input) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else if (ch == ')' || ch == ']' || ch == '}') {
                if (st.empty()) {
                    Answer = "no";
                    break;
                }
                char top = st.top();
                st.pop();
                if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                    Answer = "no";
                    break;
                }
            }
        }

        if (!st.empty()) {
            Answer = "no";
        }

        cout << Answer << '\n';
    }

    return 0;
}
