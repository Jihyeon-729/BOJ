#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, num;
int mapdata[100][100];
bool visited[100][100] = {0, };

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void init(void);
void mark(int i, int j);
int get_dist(int marker);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int min_dist = (~0u >> 2);

    init();
    for(int i=1; i<=num; i++) {
        min_dist = min(min_dist, get_dist(i));
    }

    cout << min_dist-1 << "\n";

    return 0;
}

void init(void) {

    // 추가 (메모리 초과)
    vector<pii> vpii;

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> mapdata[i][j];
            if(mapdata[i][j] == 1)
                vpii.push_back({i, j});
        }
    }

    num = 1;
    for(int i=0; i<vpii.size(); i++) {
        int y = vpii[i].first;
        int x = vpii[i].second;
        if (visited[y][x]) continue;
        mark(y, x);
        num++;
    }

/*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mapdata[i][j] << " ";
        }
        cout << "\n";
    }
    */
}

void mark(int y, int x) {

    queue<pii> qpii;
    qpii.push({y, x});

    mapdata[y][x] = num;
    visited[y][x] = true;

    while (!qpii.empty()){
        int cy = qpii.front().first;
        int cx = qpii.front().second;
        qpii.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (visited[ny][nx]) continue;
            if (mapdata[ny][nx] == 0) continue;

            mapdata[ny][nx] = num;
            visited[ny][nx] = true;
            qpii.push({ny, nx});
        }
    }

}

int get_dist(int marker) {
    
    memset(visited, false, sizeof(visited));

    pii curr, next;
    queue<pair<pii, int>> qpii;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(mapdata[i][j] == marker) {
                qpii.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }
    
    while(!qpii.empty()){
        int cy = qpii.front().first.first;
        int cx = qpii.front().first.second;
        int cd = qpii.front().second;
        qpii.pop();

        // cout << cy << " " << cx << " / ";

        for(int i=0; i<4; i++) {
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            
            if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
            if (mapdata[ny][nx] == marker) continue;
            if (visited[ny][nx]) continue;

            //if (mapdata[ny][nx] != marker && mapdata[ny][nx] != 0)
            if (mapdata[ny][nx] != 0) return cd+1;

            visited[ny][nx] = true;
            qpii.push({{ny, nx}, cd + 1});
        }
    }

    // cout << "\n";

    return (~0u >> 2);
}