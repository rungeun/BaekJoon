#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > 0) {      // 1,4
        if (y > 0) {  // 1��
            printf("1");
        } else {
            printf("4");  // 4��
        }
    } else {          // 2,3
        if (y > 0) {  // 2��
            printf("2");
        } else {
            printf("3");  // 3��
        }
    }
    return 0;
}