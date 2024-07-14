#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X,Y) cout<< X << "_TEST: " << Y << '\n';
using namespace std;

int BruteForce(int* arr, int N, int M);

int main(void) {
    int N, M;
    int arr[100];

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << BruteForce(arr, N, M);

    return 0;
}

int BruteForce(int* arr, int N, int M) {
    int result = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j+ 1; k < N; k++) {
                // TEST("i",i);
                // TEST("j",j);
                // TEST("k",k);
                sum = arr[i] + arr[j] + arr[k];
                //TEST("SUM",sum);
                if (sum > result && sum <= M) {
                    result = sum;
                }
            }
        }
    }
    return result;
}