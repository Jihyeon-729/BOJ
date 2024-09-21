#include <stdio.h>
#include <string.h>
#define MAX 100001

int t, n;
int at, included;
int nextnode[MAX];
int visited[MAX];

void init(void);
void dfs(int cur);

int main(void)
{
    scanf("%d", &t);
    while (t--)
    {
        init();
        for (int i = 1; i <= n; i++) {
            at = 0;
            if (visited[i] == -1)
                dfs(i);
        }
        printf("%d\n", n-included);
    }

    return 0;
}

void init(void)
{
    memset(visited, -1, sizeof(visited));
    included = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nextnode[i]);
    }
}

void dfs(int cur)
{
    visited[cur] = ++at;

    int nxt = nextnode[cur];
    if (visited[nxt] == -1)
        dfs(nxt);
    else if (visited[nxt] != 0)  {
        included += (visited[cur] - visited[nxt] + 1);
    } 

    visited[cur] = 0;
    return;
}