#include <iostream>

using namespace std;

string Answer;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n[3] = {0};
    int temp = 0;
    while (true) {
        n[0] = 0;
        for (int i = 0; i < 3; i++) {
            cin >> n[i];
            if (n[i] > n[0]) {  // n의 0번째 인덱스에 가장 큰 값이 들어감
                temp = n[0];
                n[0] = n[i];
                n[i] = temp;
            }
        }
        if (n[0] != 0 && n[0] == n[1] && n[1] == n[2]) {
            Answer = "Equilateral";
        } else if (n[0] == 0 && n[0] == n[1] && n[1] == n[2]) {
            break;
        } else if (n[0] >= n[1] + n[2]) {
            Answer = "Invalid";
        } else if (n[0] != n[1] && n[1] != n[2] && n[0] != n[2]) {
            Answer = "Scalene";
        } else {
            Answer = "Isosceles";
        }
        cout << Answer << endl;
    }

    return 0;
}