/*
segment tree
- 초기화: O(N), 탐색: O(logN)
- [i,j]가 주어지더라도 포함된 구간들의 합집합으로 표현 가능
- 1차원 배열로 저장
- 배열의 크기: 가장 가까운 2의 거듭제곱으로 n을 올림한후 2를 곱합(ex. n=6일 경우 8*2=16), 또는 4n으로 하기(단, 메모리 낭비가 있음)
- 노드i : 왼쪽 자식 2*i, 오른쪽 자식 2*i+1
- query: 질의 연산(임의의 구간의 값(최소, 최대, 합) 구하기)
- :노드가 표현하는 구간을 절반으로 나눠 재귀 호출 했을 때, 해당 구간이 노드에 완전히 포함 되거나 아예 포함도지 않는 다면 종료

*/

// 배열의 구간 최소 쿼리를 해결하기 위한 구간 트리의 구현
#pragma GCC optimize("O3,Ofast,unroll-loops")
#include <bits/stdc++.h>
#define TEST(X, Y) cout << X << "_TEST: " << Y << '\n'
using namespace std;
const int INF = INT_MAX;

struct RMQ {
    int n;                 // 배열의 길이
    vector<int> rangeMin;  // 각 구간의 최소치
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(n * 4);  // 세그먼트 트리의 크기를 4n으로 설정
        init(array, 0, n - 1, 1);
    }

    // node 노드가 array[left...right] 배열을 표현할 때
    // node를 루트로 하는 서브트리를 초기화하고, 이 구간의 최소치를 반환
    int init(const vector<int>& array, int l, int r, int node) {  // 트리, 왼쪽 자식, 오른쪽 자식, 현재 노드위치
        if (l == r) return rangeMin[node] = array[l];
        int mid = (l + r) / 2;
        int lMin = init(array, l, mid, node * 2);          // 왼쪽 자식 초기화  // n=5일경우 왼쪽 자식 0~2
        int rMin = init(array, mid + 1, r, node * 2 + 1);  // 오른쪽 자식 초기화// n=5일경우 오른쪽 자식 3~4
        return rangeMin[node] = min(lMin, rMin);           // 두 자식의 최소값을 저장
    }

    // node가 표현하는 범위 array[nl...nr]가 주어질 때
    // 이 범위와 array[l...r]의 교집합의 최소치를 구한다
    int query(int l, int r, int node, int nl, int nr) {  // 찾고자 하는 구간(l,r) , 현재(node)인덱스, node가 표현하는 범위(nl,nr) -> 교집합의 최소원소를 반환
        // 두 구간이 겹치지 않으면 아주 큰 값을 반환한다: 무시됨
        if (r < nl || nr < l) return INF;
        // node가 표현하는 범위가 array[l...r]에 완전히 포함되는 경우
        if (l <= nl && nr <= r) return rangeMin[node];
        // 양쪽 구간을 나눠서 푼 뒤 결과를 합친다.
        int mid = (nl + nr) / 2;
        return min(query(l, r, node * 2, nl, mid), query(l, r, node * 2 + 1, mid + 1, nr));
    }
    // query()를 외부에서 호출하기 위한 인터페이스
    int query(int l, int r) { return query(l, r, 1, 0, n - 1); }

    // array[index]=newValue로 바뀌었을 때 node를 루트로 하는
    // 구간 트리를 갱신하고 노드가 표현하는 구간의 최소치를 반환한다.
    int update(int index, int newValue, int node, int nl, int nr) {
        // index가 노드가 표현하는 구간과 상관없는 경우엔 무시한다.
        if (index < nl || nr < index) return rangeMin[node];
        // 트리의 리프까지 내려온 경우
        if (nl == nr) return rangeMin[node] = newValue;
        int mid = (nl + nr) / 2;
        return rangeMin[node] = min(update(index, newValue, node * 2, nl, mid), update(index, newValue, node * 2 + 1, mid + 1, nr));
    }
    // update()를 외부에서 호출하기 위한 인터페이스
    int update(int index, int newValue) { return update(index, newValue, 1, 0, n - 1); }
};
int main(void) {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    cin >> N;
    for (int _ = 0; _ < N; _++) {
    }
    // cout << Answer;
    return 0;
}