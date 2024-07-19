<!--풀이 완료 문제-->
# PS_Archive
|DATE| NO | 문제 | 분류 | 난이도 | TAG(me) | Comment |
|------|----|------|------|--------|-----|---------|
|24/07/08|[8979](https://www.acmicpc.net/problem/8979)|올림픽| `Math` `implementation` |Sliver5| `implementation` |각 메달 종류마다 if문을 걸어 자신의 메달보다 높을 경우 순위를 카운팅함
|24/07/09|[2166](https://www.acmicpc.net/problem/2166)|다각형의 면적|`geometry`|Gold5|`geometry`|수식을 만들어 풀었지만 예외(오목한 다각형)가 있어 수정함 $S = \frac{1}{2} \mid \sum_i^n ( x_{i} + x_{i+1} )( y_{i} - y_{i+1} ) \mid$ 수식을 이용하여 품|
|24/07/10|[15649](https://www.acmicpc.net/problem/15649) |N과 M(1)|`backtracking`| Sliver3|`backtracking`|백트랙킹으로 가능한 모든 경우 실행|
|24/07/10|[10828](https://www.acmicpc.net/problem/10828)|스택|`data_structures` `implementation` `stack`|Sliver4|`stack`|스택라이브러리를 사용하여 스택연산을 수행함|
|24/07/11|[10818](https://www.acmicpc.net/problem/10818)|최소, 최대|`Math` `implementation`|Bronze3|`segment_Tree`|세그먼트 트리를 구현하여 최솟값, 최댓값에 대해 쿼리,업데이트를 함| 
|24/07/12|[1920](https://www.acmicpc.net/problem/1920)|수 찾기|`binary search` `sorting`||`binary search` `sorting`|배열을 정렬후 X라는 수를 찾기 위해 이분 탐색을 함 (l, r, mid)| 
|24/07/12|[2751](https://www.acmicpc.net/problem/2751)|수 정렬하기2|`sorting`|Silver5|`sorting`|O(n*logn)의 시간복잡도를 가지는 sort(시작주소, 끝주소)를 사용하여 품| 
|24/07/12|[1654](https://www.acmicpc.net/problem/1654)|랜선 자르기|`binary search`|Sliver2|`binary search`|자른 개수가 N보다 작다면 r=mid-1, N보다 크다면 mid+1, 같을 경우 Answer=mid| 
|24/07/14|[10816](https://www.acmicpc.net/problem/10816)|숫자 카드2|`binary search` `data structures` `hash set` `sorting`|Sliver4|`binary search` `sorting`|원하는 M값의 개수를 찾기 위해 이분 탐색으로 가장 앞에 있는 M과 가능 뒤에 있는 M의 인덱스를 구하여 인덱스로 차로 개수를 구함|
|24/07/14|[2164](https://www.acmicpc.net/problem/2164)|카드2|`data structures` `queue`|Sliver4|`queue`| 1개의 큐를 사용하여 front의 값을 pop, front의 값을 psuh, front의 값을 pop을 반복하여 큐에 1개의 원소만 남을때 까지 반복함| 
|24/07/14|[4949](https://www.acmicpc.net/problem/4949)|균형잡힌 세상|`stack` `data structures` `string`|Sliver4|`stack` `data structures` `string`|각 경우에 따라 'no'를 출력(1.스택이 비었음에도 오른쪽 괄호가 있는 경우, 2.스택에 있는 괄호와 짝이 맞지 않는 경우, 3.검사가 끝남음에도 스택이 비어있지 않은 경우), `getline(cin, input);`를 사용하여 문자열 한줄을 입력받음| 
|24/07/15|[2839](https://www.acmicpc.net/problem/2839)|설탕 배달|`dp` `greedy` `math`|Sliver4|`dp`|`memoization`을 사용하여 재귀적 탐색을 함, cache를 사용하여 이미 계산된 (a, b) 조합의 결과를 저장하고, 중복 계산을 피함 1.(5a + 3b)가 N을 초과하면 INF 반환 2.(5a + 3b)가 N과 같으면 a + b를 반환 3.a(5kg)와 b(3kg)를 1씩 증가시키면서 재귀적으로 호출| 
|24/07/16|[11659](https://www.acmicpc.net/problem/11659)|구간 합 구하기 4|`prefix_sum`|Sliver3|`Fenwick Tree`| `Fenwick Tree`구조로 구간을 나누어 구간 합을 구함 구간 i와 j일 경우: fenwick.sum(j) - fenwick.sum(i - 1)|
|24/07/17|[2042](https://www.acmicpc.net/problem/2042)|구간 합 구하기|`data structures` `segmentTree`|Gold1|`Fenwick Tree`|앞에서 사용했던 구조체 `Fenwick Tree`를 함수형태로 바꿔 재사용함, 팬윅 트리 업데이트 오개념을 바로 잡음|
|24/07/18|[2357](https://www.acmicpc.net/problem/2357)|최솟값과 최댓값|`data structures` `segmentTree`|Gold1|`data structures` `segmentTree`|세그먼트 트리로 구간 최솟값과 최댓값에 대한 update, query를 각각 만듬,$$minT[i]=min(minT[i<<1], minT[i<<1 \mid 1]);$$ $$maxT[i]=max(maxT[i<<1], maxT[i<<1 \mid 1]);$$|
|24/07/18|[10868](https://www.acmicpc.net/problem/10868)|최솟값|`data structures` `segmentTree`|Gold1|`data structures` `segmentTree`|세그먼트 트리로 구간 최솟값 update, query를 만듬, $$minT[i]=min(minT[i<<1], minT[i<<1 \mid 1]);$$|
|24/07/18|[11505](https://www.acmicpc.net/problem/10505)|구간 곱 구하기|`data structures` `segmentTree`|Gold1|`data structures` `segmentTree`|세그먼트 트리로 군간 곱에 대한 update, query를 만듬, $$mulT[i]=((mulT[i<<1] MOD m)*(mulT[i<<1\mid1]MODm))MODm;$$|
|24/07/18|[1275](https://www.acmicpc.net/problem/1275)|커피숍2|`data structures` `segmentTree`|Gold1|`data structures` `segmentTree`|세그먼트 트리로 군간 합에 대한 update, query를 만듬, $$sumT[i] = sumT[i << 1] + sumT[i << 1 \mid 1]$$|
|24/07/18|[2268](https://www.acmicpc.net/problem/2268)|수들의 합 7|`data structures` `segmentTree`|Gold1|`data structures` `segmentTree`|세그먼트 트리로 군간 합에 대한 update, query를 만듬, $$sumT[i] = sumT[i << 1] + sumT[i << 1 \mid 1]$$|
|24/07/18|[14428](https://www.acmicpc.net/problem/14428)|수열과 쿼리 16|`data structures` `segmentTree`|Gold1|`data structures` `segmentTree`|세그먼트를 변형해서 인덱스 번호를 저장하거나, 최솟값을 구하는 세그먼트로도 가능하다. 배열을 하나 만들어서 값을 저장해두고 최솟값으로 start,end를 탐색하여 첫 번째로 나오는 인덱스 번호 출력하면 됨|
|24/07/19|[14438](https://www.acmicpc.net/problem/14438)|수열과 쿼리 17|`data structures` `segmentTree`|Gold1|`data structures` `segmentTree`|세그먼트 트리 수정하여 안정적으로 만듬, $$return \ min(query(s, e, node << 1, ns, mid), \ query(s, e, node << 1 \mid 1, mid + 1, ne));$$|
|24/07/19|[5676](https://www.acmicpc.net/problem/5676)|음주 코딩|`data structures` `segmentTree`|Gold1|`data structures` `segmentTree`|구간의 곱을 구하여 음수,0,양수를 판단하는 문제이므로 트리에 입력받은 정수를 저장하지 않고, -1,0,1만 저장하여 계산하는 값을 작게함, EOF 처리를 함|
|24/07/19|[18436](https://www.acmicpc.net/problem/18436)|수열과 쿼리 37|`data structures` `segmentTree`|Gold1|`data structures` `segmentTree`|구간의 합은 짝수,홀수인지 퀴리를 하는 문제이므로 시그먼트 트리에 입력받은 정수를 저장하지 않고 짝수일 경우에만 1을 저장하면 구간의 합은 짝수의 개수가 됨, 또한 (구한의 길이)-(짝수의 개수)를 하면 홀수의 개수도 또한 구할 수 있음|
|24/07/|[]()||``||``||
|24/07/|[]()||``||``||
|24/07/|[]()||``||``||

*실버 이상만 기록( 단, 브론즈 문제일지라도 특정 알고리즘을 테스트하기 위한 PS라면 기록함.)

<!--도전중인 문제-->
# PS_Challenging
|DATE| NO | 문제| TAG(me) | Comment |
|------|----|------|-----|---------|
|24/07/16|[9663](https://www.acmicpc.net/problem/9663)|N-Queen|`backtracking`|현재는 `segment_Tree` `Fenwick Tree`를 학습중이므로 `dp`문제들은 잠시 보류 |
|24/07/|[]()||``|`bitmask` 학습 예정| 
|24/07/|[]()||``||

<!--
임시 메모

1  : Bronze V
2  : Bronze IV
3  : Bronze III
4  : Bronze II
5  : Bronze I
6  : Silver V
7  : Silver IV
8  : Silver III
9  : Silver II
10 : Silver I
11 : Gold V
12 : Gold IV
13 : Gold III
14 : Gold II
15 : Gold I
16 : Platinum V
17 : Platinum IV
18 : Platinum III
19 : Platinum II
20 : Platinum I


-->

