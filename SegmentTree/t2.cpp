/*
Fenwick Tree
*/
#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int sz = 1 << 17;
const int INF = INT_MAX;
ll a[sz];
int Answer = 0;

// 팬윅 트리의 구현 : 가상의 배열 A[]의 부분 합을 빠르게
// 구현할 수 있도록 한다. 초기화시에는 A[]의
// 원소가 전부 0이라고 생각한다.
struct FenwickTree {
    vector<int> tree;
    FenwickTree(int n) : tree(n + 1) {}
    // A[0...pos]의 부분합을 구한다.
    int sum(int pos) {
        // 인덱스가 1부터 시작한다고 생각한다.
        ++pos;
        int ret = 0;
        while (pos > 0) {
            ret += tree[pos];
            // 다음 구간을 찾기위해 최종 비트를 지운다.
            pos &= (pos - 1);
        }
        return ret;
    }
    // A[pos]에 val을 더한다.
    void add(int pos, int val) {
        ++pos;
        while (pos < tree.size()) {
            tree[pos] += val;
            // 마지막 비트 추출
            pos += (pos & -pos);
        }
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    cin >> N;
    for (int _ = 0; _ < N; _++) {
    }
    cout << Answer;
    return 0;
}

/*
//구간 합 구하기 4 11659

#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;

struct FenwickTree {
    vector<int> tree;
    FenwickTree(int n) : tree(n + 1) {}

    // A[0...pos]의 부분합을 구한다.
    int sum(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    // A[pos]에 val을 더한다.
    void add(int pos, int val) {
        while (pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    FenwickTree fenwick(N);
    vector<int> arr(N + 1);  // 1부터 시작하기 위해 크기를 N+1로 설정

    // 수열 입력 받기
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        fenwick.add(i, arr[i]);
    }

    // 각 쿼리 처리
    for (int q = 0; q < M; q++) {
        int i, j;
        cin >> i >> j;
        int sum_j = fenwick.sum(j);
        int sum_i = fenwick.sum(i - 1);
        cout << sum_j - sum_i << '\n';
    }

    return 0;
}


*/