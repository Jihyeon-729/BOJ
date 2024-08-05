// 세그먼트 트리 : O (N log N)
// 여러 데이터 특정 구간의 합(최솟값, 최댓값, 곱 등) 구하는 데 사용

// 시간 : O(NlogN), 요청 O(N+M) (자료개수 + 구간크기)
// 공간 : O(NlogN) (트리 높이 * leaf 너비)

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000000001
#define MAX_ARR 100001
#define MAX_TREE 2000001

int n, m;
int arr[MAX_ARR];
int tree[MAX_TREE];

int init(int from, int to, int node);
int find(int from, int to, int node, int left, int right);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++)
        cin >> arr[i];

    init(0, n-1, 1);

    int from, to;
    for (int i=0; i<m; i++) {
        cin >> from >> to;
        cout << find(0, n-1, 1, from-1, to-1) << "\n";
    }

    return 0;
}

// 트리 만드는 함수
int init(int from, int to, int node)
{
    if (from == to)
        return tree[node] = arr[from];

    int mid = (from + to)/2;
    int minVal = min(init(from, mid, node*2), init(mid+1, to, node*2+1));
    return tree[node] = minVal;
}

// 최솟값 찾는 함수
int find(int from, int to, int node, int left, int right)
{
    if (left > to || right < from) return MAX;
    if (left <= from && to <= right) return tree[node];

    int mid = (from+to) / 2;
    int minVal = min(find(from, mid, 2 * node, left, right), find(mid + 1, to, 2 * node + 1, left, right));

    return minVal;
}
