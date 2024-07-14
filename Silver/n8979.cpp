#include <algorithm>
#include <iostream>
#define MAX 20
using namespace std;

int Answer;

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, K, x;
    int arr[1000][3] = {0};
    int check;
    cin >> N >> K;
    Answer = 1;

    for (int i = 0; i < N; i++) {
        cin >> x;
        cin >> arr[x - 1][0];
        cin >> arr[x - 1][1];
        cin >> arr[x - 1][2];
    }
    for (int i = 0; i < N; i++) {
        if (arr[i][0] > arr[K - 1][0]) {
            Answer++;
        } else if (arr[i][0] == arr[K - 1][0]) {
            if (arr[i][1] > arr[K - 1][1]) {
                Answer++;
            } else if (arr[i][1] == arr[K - 1][1]) {
                if (arr[i][2] > arr[K - 1][2]) {
                    Answer++;
                }
            }
        }
    }
    cout << Answer << endl;

    return 0;
}