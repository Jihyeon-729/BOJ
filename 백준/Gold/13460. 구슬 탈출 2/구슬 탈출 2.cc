#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int ry, rx;
    int by, bx;
    int tilted;
} Beads;

typedef struct {
    int y, x, d;
} Moved;

int N, M;
char board[10][10];
bool visited[10][10][10][10];
queue<Beads> bq;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void BFS(void);
Moved move(int x, int y, int d, int i);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int ry, rx, by, bx;
    ry=0; rx=0; by=0; bx=0;

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                ry = i; rx = j;
            } else if (board[i][j] == 'B') {
                by = i; bx = j;
            }
        }
    }

    bq.push({ry, rx, by, bx, 0});
    visited[ry][rx][by][bx] = true;
    BFS();

    return 0;
}

void BFS(void) {
    int ry, rx, by, bx, tilted;
    Beads beads;

    while(!bq.empty()) {
        beads = bq.front();
        ry = beads.ry;
        rx = beads.rx;
        by = beads.by;
        bx = beads.bx;
        tilted = beads.tilted;
        bq.pop();

        if(tilted >= 10) break;

        for(int i=0; i<4; i++) {

            Moved rm, bm;
            rm = move(ry, rx, 0, i);
            bm = move(by, bx, 0, i);

            // 파랑 구슬이 구멍에 빠지면 실패 (빨강이 구멍에 빠져도)
            if(board[bm.y][bm.x] == 'O') continue;
            if(board[rm.y][rm.x] == 'O') {
                cout << tilted+1 << "\n"; return;
            }

            // 구슬 겹침
            if (rm.y == bm.y && rm.x == bm.x) {
                // 이동거리 더 긴 구슬을 한칸 뒤로
                if(rm.d > bm.d) { rm.y -= dy[i]; rm.x -= dx[i];}
                else { bm.y -= dy[i]; bm.x -= dx[i];}
            }

            if (visited[rm.y][rm.x][bm.y][bm.x]) continue;

            visited[rm.y][rm.x][bm.y][bm.x] = true;
            bq.push({rm.y, rm.x, bm.y, bm.x, tilted+1});
        }
    }

    cout << "-1\n";
    return;
}

Moved move(int y, int x, int d, int i) {
    int ny=y, nx=x, nd=d;
    while (board[ny + dy[i]][nx + dx[i]] != '#' && board[ny][nx] != 'O') {
        ny += dy[i]; nx += dx[i];
        nd += 1;
    }
    return {ny, nx, nd};
}