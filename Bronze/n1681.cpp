#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, count = 0, result = 0;
    char l;
    cin >> n >> l;
    
    int i = 1;  
    
    while (count < n) {
        string strN = to_string(i);
        bool hasL = false;
        
        for (char ch : strN) {
            if (ch == l) {
                hasL = true;
                break;
            }
        }
        
        if (!hasL) {
            result = i;
            count++;
        }
        
        i++;
    }

    cout << result << endl;

    return 0;
}
