#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
    int h, m;
    scanf("%d %d", &h, &m);
    if (m - 45 >= 0) {  // �� ��ȭ�� ���� ���
        printf("%d %d", h, m - 45);
    } else {  // �� ��ȭ�� �ִ� ���
        h--;  // 3:40 -> 2:55
        m += 15;
        if (h >= 0) {  // ������ �ѱ��� ���� ���
            printf("%d %d", h, m);
        } else {
            h = 23;
            printf("%d %d", h, m);  // ������ �ѱ� ���
        }
    }

    return 0;
}