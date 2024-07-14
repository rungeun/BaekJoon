#include <iostream>

using namespace std;

string Answer;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    cin >> N;
    if(N%2 ==0){
        Answer="CY";
    }
    else{
        Answer="SK";
    }

    cout << Answer << endl;

    return 0;
}