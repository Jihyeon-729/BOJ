#include <vector>
#include <queue>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
bool visited[100][100];

typedef struct {
    int y, x, depth;
} LOCATION;

int solution(vector<vector<int> > maps)
{    
    int ans = -1;
    int row = maps.size();
    int col = maps[0].size();
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(maps[i][j] == 0)
                visited[i][j] = 1;
        }
    }
    
    queue<LOCATION> q;
    LOCATION loc, newloc;
    
    loc.y = 0; loc.x = 0; loc.depth = 1;
    visited[0][0] = true;
    q.push(loc);
    while(!q.empty()) {
        loc = q.front();
        q.pop();
        // 목표지점에 도달한 경우
        if(loc.y==row-1 && loc.x==col-1) {
            ans = loc.depth;
            break;
        }
        for(int i=0; i<4; i++) {
            newloc.y = loc.y + dy[i];
            newloc.x = loc.x + dx[i];
            newloc.depth = loc.depth+1;
            // 범위 안이고, 방문한 적 없는 블록이면 큐에 push
            if(0<=newloc.y&&newloc.y<row && 0<=newloc.x&&newloc.x<col) {
                if(!visited[newloc.y][newloc.x]) {
                    // 큐에 넣기 전에 visited 표시해준다.
                    visited[newloc.y][newloc.x] = true;
                    q.push(newloc);
                }
            }
        }
    }
    
    return ans;
}

/*
bool found;
int row, col;
int ans = -1;

void DFS(int y, int x, int depth);

int solution(vector<vector<int> > maps)
{    
    row = maps.size();
    col = maps[0].size();
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(maps[i][j] == 0) visited[i][j] = true;
        }
    }
    
    DFS(0, 0, 1);
    
    return ans;
}

void DFS(int y, int x, int depth)
{
    int ny, nx;
    if(!found) {
        visited[y][x] = true;
        if(y==row-1 && x==col-1) {
            ans = depth;
            found = true;
            visited[y][x] = false;
            return;
        }
        for(int i=0; i<4; i++) {
            ny = y+dy[i];
            nx = x+dx[i];
            if(0<=ny&&ny<row && 0<=nx&&nx<col && !visited[ny][nx]) {
                DFS(ny, nx, depth+1);
            }
        }
        visited[y][x] = false;
    }
}
*/