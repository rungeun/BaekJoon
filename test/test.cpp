#include <stdio.h>
#include <string.h>

int memo[2211];

int f(int n) {
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];  // 이미 계산된 경우 반환

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += f(i);
    
    return memo[n] = sum % 13;  // 결과를 메모이제이션 배열에 저장
}

int main() {
    // 메모이제이션 배열 초기화
    memset(memo, -1, sizeof(memo));
    
    char ans[] = "rgjgmbuyhbfcx";
    for (int i = 0; i < 13; i++)
        ans[i] ^= f(13 + i * i * i);
    puts(ans);
    return 0;
}
