#include <algorithm>
#include <iostream>
using namespace std;

char Answer;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    string str;
    int count[26] = {0};
    int max = 0;

    cin >> str;
    // A65 Z90 a97 z122
    for (int i = 0; i < str.size(); i++) {
        if (str[i] > 90) {
            count[str[i] - 97]++;
        } else {
            count[str[i] - 65]++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] > count[max]) {
            max = i;
        }
    }
    Answer = max + 65;

    sort(count, count + 26);
    if (count[24] == count[25]) {
        Answer = '?';
    }
    cout << Answer << endl;
    return 0;
}