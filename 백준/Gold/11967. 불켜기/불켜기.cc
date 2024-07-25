#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

#define pii pair<int, int>

typedef struct {
    int x, y;
} Loc;

int N, M;
int light[101][101], visited[101][101], movable[101][101];

vector<Loc> room[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(void);

int main()
{
    cin >> N >> M;
    while (M--)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        room[x][y].push_back({a, b});
    }
    cout << bfs();
}

int bfs(void)
{
    int ans = 0;
    visited[1][1] = 1;
    light[1][1] = 1;

    queue<pii> q;
    q.push({1, 1});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (auto &r : room[x][y])
            light[r.x][r.y] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (1 > nx || nx > N || 1 > ny || ny > N) continue;
            movable[nx][ny] = 1;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (!light[i][j] || visited[i][j] || !movable[i][j])
                    continue;
                visited[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (light[i][j])
                ans++;
        }
    }

    return ans;
}