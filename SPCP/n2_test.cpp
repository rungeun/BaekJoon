#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

        Answer = 0;
        /////////////////////////////////////////////////////////////////////////////////////////////
        int N;
        int arr[300000 + 1];
        int findIndex;
        cin >> N;

        for(int i=0; i<N; i++){
            cin>> arr[i];
        }

        int a, d;
        
        for (int i = 0; i < N/4; i++) {
            a= arr[i];
            findIndex= i + (3* N /4);
            d=arr[findIndex];
            Answer += (2*d) - (2*a);
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        cout << Answer << endl;
  

    return 0;
}