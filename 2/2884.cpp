#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
    int h, m;
    scanf("%d %d", &h, &m);
    if (m - 45 >= 0) {  // 시 변화가 없는 경우
        printf("%d %d", h, m - 45);
    } else {  // 시 변화가 있는 경우
        h--;  // 3:40 -> 2:55
        m += 15;
        if (h >= 0) {  // 자정을 넘기지 않은 경우
            printf("%d %d", h, m);
        } else {
            h = 23;
            printf("%d %d", h, m);  // 자정을 넘긴 경우
        }
    }

    return 0;
}