#include <string>
#include <vector>
#include <iostream>

/* 새로 배운 것
1) 다차원 벡터 초기화 : fill(v.begin(), v.end(), vector<int>(3, 0));
리마인드 (최적화 관점)
1) 벡터보단 배열이 빠르다
2) 함수 스택 생성 시 인자가 너무 많으면 시간이 오래 걸린다.
*/

// cost를 DP로 풀지 않으면 테케 3개에서 시간 초과가 난다. (88점 - #10, 11, 19)

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool found = false;
int answer = 375000, row, col;
bool visited[25][25] = {0, };
int brd[25][25] = {0, };
int cost[25][25] = {0, };

void DFS(int y, int x, int prevDir);

int solution(vector<vector<int>> board) {
    row = board.size();
    col = board[0].size();
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            brd[i][j] = board[i][j];
        }
    }
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cost[i][j] = 375000;
        }
    }
    cost[0][0] = 0;
    DFS(0, 0, -1);
    
    return answer;
}

//void DFS(vector<vector<int>> board, int y, int x, int prevDir, int cost)
void DFS(int y, int x, int prevDir)
{
    int ny, nx, nc;
    if(cost[y][x] > answer) return;
    
    // 목표 지점이면
    if(y==row-1 && x==col-1) {                
        if (cost[y][x] < answer) 
            answer = cost[y][x];
        return;
    }
    
    visited[y][x] = true;
    for(int i=0; i<4; i++) {
        ny=y+dy[i]; nx=x+dx[i];
        // 계산한 좌표가 board 범위 이내이고
        // visited 아니고 벽이 아닐 때 cost 갱신하고 DFS
        if(0<=ny&&ny<row && 0<=nx&&nx<col && !visited[ny][nx] && brd[ny][nx]!=1) {
            if((prevDir == i || prevDir == -1) && (cost[y][x]+100<=cost[ny][nx])) {
                cost[ny][nx] = cost[y][x]+100;
                DFS(ny, nx, i);
            }
            else if ((prevDir != i && prevDir != -1) && (cost[y][x]+600<=cost[ny][nx])) {
                cost[ny][nx] = cost[y][x]+600;
                /*for(int j=0; j<row; j++) {
                    for(int k=0; k<col; k++) {
                        cout << cost[j][k] << "\t\t";
                    } cout << "\n";
                } cout << "\n";
                */
                DFS(ny, nx, i);
            }
            //if(found && nc>answer) continue;
        }
    }
    visited[y][x] = false;
    return;
}

/*
//void DFS(vector<vector<int>> board, int y, int x, int prevDir, int cost)
void DFS(int y, int x, int prevDir)
{
    int ny, nx, nc;
    
    // 경로 찾았는데, 다른경로 탐색 중 cost가 최소 cost보다 커진다면 탐색 중단
    if(found && cost+100>answer) return;
    
    // 목표 지점이면
    if(y==row-1 && x==col-1) {                
        if (cost < answer) answer = cost;
        found = true;
        return;
    }
    
    visited[y][x] = true;
    for(int i=0; i<4; i++) {
        ny=y+dy[i]; nx=x+dx[i];
        // 계산한 좌표가 board 범위 이내이고
        // visited 아니고 벽이 아닐 때 cost 갱신하고 DFS
        if(0<=ny&&ny<row && 0<=nx&&nx<col && !visited[ny][nx] && brd[ny][nx]!=1) {
            if(prevDir == i || prevDir == -1) 
                nc = cost + 100;
            else nc = cost + 600;
            //if(found && nc>answer) continue;
            DFS(ny, nx, i, nc);
        }
    }
    visited[y][x] = false;
    return;
}
*/