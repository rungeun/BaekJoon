#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
    int a;
    scanf("%d", &a);
    if (a >= 80) {
        if (a >= 90) {
            printf("A");
        } else {
            printf("B");
        }
    } else if (a >= 60) {
        if (a >= 70) {
            printf("C");
        } else {
            printf("D");
        }
    } else {
        printf("F");
    }

    return 0;
}