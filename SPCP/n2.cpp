#include <algorithm>
#include <iostream>
using namespace std;

long long Answer;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, test_case;

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {
        Answer = 0;
        /////////////////////////////////////////////////////////////////////////////////////////////
        int N;
        int arr[300000 + 1] = {0};
        int findIndex;

        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + N);

        int a, d;
  
        for (int i = 0; i < N / 4; i++) {
            a = arr[i];
            findIndex = i + (3 * N / 4);
            d = arr[findIndex];
            Answer += (2 * d) - (2 * a);
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}