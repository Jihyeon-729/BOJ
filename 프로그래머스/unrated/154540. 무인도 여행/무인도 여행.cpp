#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
bool visited[102][102];

int DFS(int cx, int cy, vector<string> maps);

vector<int> solution(vector<string> maps) {
    int days;
    vector<int> answer;

    // DFS
    for(int i=0; i<maps.size(); i++) { // height
        for(int j=0; j<maps[0].size(); j++) { // width
            // elem is part of unknown island
            if(maps[i][j] != 'X' && !visited[i][j]){
                days = DFS(i, j, maps);
                answer.push_back(days);
            }
        }
    }

    sort(answer.begin(), answer.end());
    if(answer.empty())
        answer.push_back(-1);

    return answer;
}


// 앞으로 DFS, BFS format은 cy, cx로 다 통일하자 -> ny, nx 순서 때문에 헷갈려서 오래걸림
int DFS(int cy, int cx, vector<string> maps) {
    int nx, ny, days;
    days = maps[cy][cx] - '0';
    visited[cy][cx] = true;

    for(int i=0; i<4; i++) {
        nx = cx + dx[i]; ny = cy + dy[i];
        if(0<=nx&&nx<maps[0].size() && 0<=ny&&ny<maps.size()) { // in map
            if(!visited[ny][nx] && maps[ny][nx] != 'X')
                days += DFS(ny, nx, maps);
        }
    }

    return days;
}