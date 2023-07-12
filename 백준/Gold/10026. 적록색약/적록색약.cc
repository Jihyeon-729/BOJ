// dfs - gold5
// 23.07.12

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int N;
int cnt = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool visited[100][100];
char image[100][100];

void DFS(int cy, int cx);
void RG_DFS(int cy, int cx);

int main(void)
{
    string s;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> s;
        for(int j=0; j<N; j++) {
            image[i][j] = s[j];
            visited[i][j] = false;
        }
    }

    // for (int i=0; i<N; i++) {
    //     for(int j=0; j<N; j++) {
    //         cout << image[i][j] << " ";
    //     } cout << "\n";
    // }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!visited[i][j]) {
                cnt++;
                DFS(i, j);
            }
        }
    }
    cout << cnt << " ";

    cnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            visited[i][j] = false;
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!visited[i][j]) {
                cnt++;
                RG_DFS(i, j);
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}

void DFS(int cy, int cx)
{
    int ny, nx;
    visited[cy][cx] = true;
    for(int i=0; i<4; i++) {
        ny = cy + dy[i];
        nx = cx + dx[i];
        if(0<=ny && ny<N && 0<=nx && nx<N) {
            if(!visited[ny][nx] && (image[ny][nx] == image[cy][cx])) {
                DFS(ny, nx);
            }
        }
    }
    return;
}

void RG_DFS(int cy, int cx)
{
    int ny, nx;
    char cp, np;
    visited[cy][cx] = true;
    for(int i=0; i<4; i++) {
        ny = cy + dy[i];
        nx = cx + dx[i];
        cp = image[cy][cx];
        np = image[ny][nx];
        if((0<=ny && ny<N && 0<=nx && nx<N) && !visited[ny][nx]) {
            if (cp == 'R' || cp == 'G') {
                if(np == 'R' || np == 'G')
                    RG_DFS(ny, nx);
            }
            else if (cp == np) { // 'B'
                RG_DFS(ny, nx);
            }
        }
    }
    return;
}