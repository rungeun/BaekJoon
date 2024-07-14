#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > 0) {      // 1,4
        if (y > 0) {  // 1사
            printf("1");
        } else {
            printf("4");  // 4사
        }
    } else {          // 2,3
        if (y > 0) {  // 2사
            printf("2");
        } else {
            printf("3");  // 3사
        }
    }
    return 0;
}