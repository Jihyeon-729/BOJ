#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define SIZE 10
#define MAX 101

int board[SIZE][SIZE];
int answer = MAX;
int paper[6] = { 0, };

void init(void);
bool able(int y, int x, int size);
void search(int y, int x, int cnt);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();

    search(0, 0, 0);
    if (answer == MAX)
        answer = -1;

    cout << answer << endl;
    return 0;
}

void init(void) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            cin >> board[i][j];
        }
    }
    return;
}

bool able(int y, int x, int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(board[y+i][x+j] == 0)
                return false;
        }
    }
    return true;
}

void search(int r, int c, int cnt)
{
    // (y, x)에서 가장 가까운 시작 좌표 찾기
    int ny = r;
    int nx = c;
    while (board[ny][nx] == 0) {
        if ((++nx) >= SIZE) {
            if ((++ny) >= SIZE) {
                answer = min(answer, cnt);
                return;
            }
            nx = 0;
        }
    }
    // 가지치기 (어차피 최소인 answer 구하는 거니까)
    if (cnt >= answer)
        return;

    // (ny, nx)에서 조각 테스트
    for (int size=5; size>=1; size--)
    {
        // 보드 벗어나거나, 종이조각 없으면 패스
        if (ny+size > SIZE || nx+size > SIZE) continue;
        if (paper[size] >= 5) continue;

        // 사이즈만큼 모두 1로 채워져있다면
        // (종이조각 붙이기 가능하다면)
        if (able(ny, nx, size)) {

            // 종이 붙이고 0 표시
            paper[size]++;
            for(int i=0; i<size; i++) {
                for(int j=0; j<size; j++) {
                    board[ny+i][nx+j] = 0;
                }
            }

            // 다음 종이조각 붙일곳 탐색
            search(r, c, cnt + 1);

            // 종이 떼고 0표시 북구(1 표시))
            paper[size]--;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    board[ny+i][nx+j] = 1;
                }
            }
        }
    }
}