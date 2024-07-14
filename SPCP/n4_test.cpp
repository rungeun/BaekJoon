#include <algorithm>
#include <iostream>
#define X(x) x > 0 ? x : -1 * x
using namespace std;

int Answer;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, test_case;

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {
        Answer = 0;
        /////////////////////////////////////////////////////////////////////////////////////////////
        int N, L;
        int A[100000 + 1] = {0};
        int B[100000 + 1] = {0};
        int temp;
        bool check = true;
        cin >> N >> L;

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }

        sort(A, A + N);
        sort(B, B + N);

        int d = 0;
        // 경우 1
        for (int i = 0; i < N; i++) {
            if (X(B[i] - A[i]) > L) {
                d++;
            }
        }
        if (d == N) {
            check = false;
            Answer = -1;
        }
        // 경우 4
        int a = X((A[N - 1] - B[0]));
        int b = X((B[N - 1] - A[0]));
        if (a <= L && b <= L) {
            check = false;
            Answer = a > b ? a : b;
        }

        // 경우2
        for (int i = 0; i < N && check; i++) {
            temp = X(B[N - i - 1] - A[i]);
            if (temp <= L && temp > Answer) {
                Answer = temp;
            }
        }
        // 경우3
        for (int i = 1; i < N && i < 1001 && check; i++) {
            for (int j = 0; j < N && j < 1001; j++) {
                temp = X((B[j] - A[i]));
                // 경우 3-1
                if (temp == L) {
                    check = false;
                    Answer = L;
                }
                // 경우 3-2
                if (temp <= L && temp > Answer) {
                    Answer = temp;
                }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}