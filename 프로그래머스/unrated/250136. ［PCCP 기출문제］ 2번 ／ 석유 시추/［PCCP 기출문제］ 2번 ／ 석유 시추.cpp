#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int num = 2;
int row, col;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int bundle[250000] = {0, };
vector<vector<int>> _land;

void BFS(int y, int x);
void DFS(int y, int x);

int solution(vector<vector<int>> land) {
    int answer = 0;
    row = land.size();
    col = land[0].size();
    _land = land;
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if (_land[i][j]==1) {
                DFS(i, j);
                num++;
            }
        }
    }

    for(int i=0; i<col; i++) {
        int oil = 0;
        set<int> s;
        for(int j=0; j<row; j++) {
            if(_land[j][i] > 1)
                s.insert(_land[j][i]);
        }
        for(auto it: s)
            oil += bundle[it];
        answer = max(oil, answer);
    }
    
    return answer;
}

void DFS(int y, int x)
{
    int ny, nx;
    
    bundle[num]++;
    _land[y][x] = num;
    
    for(int i=0; i<4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        // 범위 안이고, 방문한 적 없고, land값이 1이면
        if(0<=ny&&ny<row && 0<=nx&&nx<col && _land[ny][nx]==1) {           
            DFS(ny, nx);
        }
    }
    return;
}