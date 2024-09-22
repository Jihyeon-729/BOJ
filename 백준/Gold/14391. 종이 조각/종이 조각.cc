#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int maxsum;

int board[4][4];

void init(void);
int sum_horz(int mask);
int sum_vert(int mask);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    for (int mask = 0; mask < (1 << (N * M)); mask++) {
        // 가로조각:bit0, 세로:bit1
        int sum = sum_horz(mask);
        sum += sum_vert(mask);
        maxsum = max(maxsum, sum);
    }
    cout << maxsum << "\n";

    return 0;
}

void init(void) {

    string num;

    maxsum = -1;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> num;
        for(int j=0; j<M; j++) {
            board[i][j] = num[j] - '0';
        }
    }
    return;
}

int sum_horz(int mask) {
    int sum_total = 0;
    for(int i=0; i<N; i++) {
        
        int sum_row = 0;
        // i번째 행의 가로조각 합 계산
        for(int j=0; j<M; j++) {

            // 셀 위치 계산 (n번째)
            int nth = i*M + j;

            // 현재 셀이 가로조각에 포함돼있다면
            if((mask & (1<<nth)) == 0) {
                sum_row = sum_row*10 + board[i][j];
            } 
            else { // 현재 셀이 세로조각에 포함돼있다면
                // 계산해왔던 가로조각 합을 total에 더하고 0으로 초기화
                sum_total += sum_row;
                sum_row = 0;
            }
        }
        sum_total += sum_row;
    }

    return sum_total;
}

int sum_vert(int mask) {

    int sum_total = 0;
    for(int j=0; j<M; j++) {
        int sum_col = 0;
        for(int i=0; i<N; i++) {
            // 셀 위치 계산
            int nth = i*M + j;
            // 현재 셀이 세로조각에 포함돼있다면
            if ((mask & (1 << nth)) != 0) {
                sum_col = sum_col * 10 + board[i][j];
            } else
            { // 현재 셀이 가로조각에 포함돼있다면
                // 계산해왔던 세로조각 합을 total에 더하고 0으로 초기화
                sum_total += sum_col;
                sum_col = 0;
            }
        }
        sum_total += sum_col;
    }

    return sum_total;
}