// DP - gold3
// 23.07.31

#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

long D[100001][5][5];
int E[5][5] = {{0, 2, 2, 2, 2},
                    {2, 1, 3, 4, 3},
                    {2, 3, 1, 3, 4},
                    {2, 4, 3, 1, 3},
                    {2, 3, 4, 3, 1}};

int main(void)
{
    int num, phase;
    long effort;

    phase = 1;
    for(int i=0; i<100001; i++) {
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                D[i][j][k] = 400001;
            }
        }
    }
    D[0][0][0] = 0;

    while(true) {
        cin >> num;
        if(num == 0) break;
        for(int i=0; i<5; i++) {
            if(num==i) continue;
            for(int j=0; j<5; j++) {
                D[phase][i][num] = min(D[phase-1][i][j]+E[j][num], D[phase][i][num]);
            }
        }
        for(int j=0; j<5; j++) {
            if(num==j) continue;
            for(int i=0; i<5; i++) {
                D[phase][num][j] = min(D[phase-1][i][j]+E[i][num], D[phase][num][j]);
            }
        }
        phase++;
    }

    phase--;
    effort = INT_MAX;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            effort = min(effort, D[phase][i][j]);
        }
    }
    cout << effort << "\n";
}