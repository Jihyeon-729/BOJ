// 빡구현..? -> X
// int arr[10001][10001];
// 100,000,000 vs 2^27 => 128,000,000

/* BFS..? -> X
1,1 2,2 3,2
2,2 3,2 4,3 5,3
3,2 4,3 5,3 6,3 7,3
4 5 67 8
5 67 8 -1 910
6 7 8-1 910
*/

// answer()에서 min, max 초기화 문제로 오답

#include <stdio.h>

int N;
int g_col, g_row;
int tree[10001][2]; // [0]:left, [1]:right
char isRoot[10001];
int width[10001][2]; //[2][0]:lv2, min col, [2][1]:lv2, max col

int input();
void inorder(int node, int row);
void answer(void);

int main(void)
{
    int root = input();
    inorder(root, 1);
    answer();

    return 0;
}

int input(void)
{
    int node, left, right;

    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        isRoot[i] = 1;    // true
 
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &node, &left, &right);
        tree[node][0] = left;
        tree[node][1] = right;
        if (left != -1) isRoot[left] = 0;
        if (right != -1) isRoot[right] = 0;
    }
    
    for (int i = 1; i <= N; i++) {
        if (isRoot[i])
            return i;
    }
}

void inorder(int node, int level)
{
    if (node == -1)
        return;
    if (g_row < level)
        g_row = level;

    // left
    inorder(tree[node][0], level + 1);

    // self
    if (width[level][0] == 0)
        width[level][0] = ++g_col;
    else
        width[level][1] = ++g_col;

    // right
    inorder(tree[node][1], level + 1);

    return;
}

void answer(void)
{
    int cur_width, min_level, max_width;
    
    min_level = 1;
    max_width = 1;
    for (int level = 2; level <= g_row; level++) {
        // 각 레벨의 너비 = (가장 오른쪽 노드 열#) - (가장 왼쪽 노드 열#) + 1
        cur_width = width[level][1] - width[level][0] + 1;
        if (max_width < cur_width)
        {
            max_width = cur_width;
            min_level = level;
        }
    }
    
    printf("%d %d\n", min_level, max_width);
    return;
}