// bfs - silver1
// 23.07.10

#include <iostream>
#include <utility>
#include <string>
#include <queue>

int dx[4] = {1, 0, -1, 0}; // ESWN
int dy[4] = {0, -1, 0, 1};

int visited[100][100];
int movable[100][100] = {0, };

using namespace std;

int main(void)
{
    string s;
    int N, M;
    int cnt = 0;
    int cx, cy, nx, ny;
    queue<pair<int,int>> q;   // x, y

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> s;
        for(int j=0; j<M; j++) {
            visited[i][j] = 0;
            if (s[j] == '1')
                movable[i][j] = 1;
            else if (s[j] == '0')
                movable[i][j] = 0;
        }
    }

    cnt = 1;
    visited[0][0] = cnt;
    q.push(make_pair(0, 0));
    while(!q.empty()) {
        cx = q.front().first;
        cy = q.front().second;
        cnt = visited[cy][cx] + 1;
        q.pop();

        for(int i=0; i<4; i++) {
            nx = cx+dx[i]; ny = cy+dy[i];
            if ((0 <= nx && nx < M) && (0 <= ny && ny < N)) { // not outbound
                if(!visited[ny][nx] && movable[ny][nx]) {
                    visited[ny][nx] = cnt;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    cout << visited[N-1][M-1] << "\n"; 

    return 0;
}