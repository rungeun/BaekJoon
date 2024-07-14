#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
    int h, m, t, a;
    scanf("%d %d %d", &h, &m, &t);

    m = m + t;
    a = m / 60;
    m %= 60;
    h = (h + a) % 24;

    printf("%d %d", h, m);
    return 0;
}
