#include <iostream>

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
        int N;
        bool check = true;
        string str;
        cin >> N;
        cin >> str;

        for (int i = 0; i < N - 1; i++) {
            if (str[i] == 'A' && str[i + 1] == 'A') {
                Answer += 2;
            } else if (str[i] == 'A' && str[i + 1] == 'B') {
                if (str[i + 2] == 'A') {
                    Answer += 1;
                }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}