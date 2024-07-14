#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string a, b;
    int count = 0;
    int c[26] = {0};

    cin >> a >> b;

    cout<< 'A'-65;    // 65 ~ 90
    
    for (int i = 0; i < a.length(); i++) {
        c[a[i]-65] = 1;
    }
    for (int i = 0; i < a.length(); i++) {
        c[b[i]-65] = 1;
    }
    for (int i = 0; i < 26; i++) {
        if (c[i] == 1) {
            count++;
        }
    }

    cout<< count;
    return 0;
}














//아래 코드는 부분수열을 구하는게 아니라 겹치는 문자의 개수를 세는 문제임
// #include <iostream>
// #include <string>
// using namespace std;

// int main(void) {
//     string a, b;
//     int count = 0;
//     int c[26] = {0};

//     cin >> a >> b;
//     // 65 ~ 90
//     cout<< 'A'-65;

//     for (int i = 0; i < a.length(); i++) {
//         c[a[i]-65] = 1;
//     }
//     for (int i = 0; i < a.length(); i++) {
//         c[b[i]-65] = 1;
//     }
//     for (int i = 0; i < 26; i++) {
//         if (c[i] == 1) {
//             count++;
//         }
//     }

//     cout<< count;
//     return 0;
// }