#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int H, W, N, M;
    int wCount = 0, hCount = 0;
    cin >> H >> W >> N >> M;

    wCount = W / (M + 1);
    hCount = H / (N + 1);
    if (W % (M + 1) > 0) {
        wCount++;
    }
    if (H % (N + 1) > 0) {
        hCount++;
    }
    Answer = wCount * hCount;

    cout << Answer;
    return 0;
}
