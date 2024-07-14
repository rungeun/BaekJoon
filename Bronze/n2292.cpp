#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    int t = 1, line = 0;
    cin >> N;
    while (t < N) {
        t += 6 * line;
        line++;
    }
    if (N == 1) {
        Answer = 1;
    } else {
        Answer = line;
    }
    cout << Answer << endl;

    return 0;
}