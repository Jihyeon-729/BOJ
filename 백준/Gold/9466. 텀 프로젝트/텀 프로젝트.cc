#include <iostream>
#include <string.h>

using namespace std;

#define MAX 100001

int t, n;
// short는 범위 3만 정도까지 밖에 안됨
int at, included;
// at: 현재 그래프에서 몇번째로 탐색됐는지
// included: 그래프(몇번째든) 속한 인원 카운트

int nextnode[MAX]; // 다음 노드 (팀 되고싶은 학생)
int visited[MAX];
// 그래프(팀) 탐색 중 몇번째로 나타났는지
// -1:탐색전, 0:탐색끝, 1~:그래프에 속함

void init(void);
void dfs(int cur);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--)
    {
        init();
        for (int i = 1; i <= n; i++)
        {
            at = 0;
            if (visited[i] == -1)
                dfs(i);
        }
        cout << n - included << "\n"; // 전체 인원수 - 팀에 포함된 인원수
    }

    return 0;
}

void init(void)
{
    memset(visited, -1, sizeof(visited));
    included = 0;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nextnode[i];
    }
}

void dfs(int cur)
{
    visited[cur] = ++at;

    int nxt = nextnode[cur];
    if (visited[nxt] == -1)
        dfs(nxt);
    // 첫번째 노드거나, 자기 자신일 때 => 가 아니고!!!!
    // else if (visited[nxt] == 1 || cur == nxt)
    // 이번 팀 탐색에서 방문한 적 있는 노드라면 (지난 팀은 안됨))
    else if (visited[nxt] != 0)
    {
        included += (visited[cur] - visited[nxt] + 1);
    } 

    visited[cur] = 0;
    return;
}