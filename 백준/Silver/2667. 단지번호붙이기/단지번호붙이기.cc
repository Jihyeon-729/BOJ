// dfs - silver1
// 23.07.10

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

int N;
int cnt = 0;
int map[25][25] = {0, };
bool visited[25][25];
vector<int> houseNum;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int row, int col);

int main(void)
{
    string s;
    
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> s;
        for(int j=0; j<N; j++) {
            map[i][j] = s[j] - '0';
            visited[i][j] = false;
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                DFS(i, j);
                houseNum.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(houseNum.begin(), houseNum.end());

    cout << houseNum.size() << "\n";
    for(int i=0; i<houseNum.size(); i++) {
        cout << houseNum[i] << "\n";
    }

    return 0;
}

void DFS(int row, int col)
{
    int cx, cy, nx, ny;
    cy = row; cx = col;
    visited[cy][cx] = true;
    cnt++;
    for(int i=0; i<N; i++) {
        ny = cy + dy[i];
        nx = cx + dx[i];
        if(0<=ny && ny<N && 0<=nx && nx<N) {
            if (map[ny][nx] == 1 && !visited[ny][nx]) {
                DFS(ny, nx);
            }
        }
    }
    return;
}