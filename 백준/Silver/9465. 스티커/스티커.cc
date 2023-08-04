// DP - silver1
// 23.08.04

#include <iostream>

using namespace std;

int main(void)
{
    int T, N;

    cin >> T;
    while(T>0) {
        int stck[2][100001] = {{0, }, {0, }};
        int D[2][100001] = {{0, }, {0, }};
        bool torn[2][100001] = {{0, }, {0, }};
        
        cin >> N;
        for(int i=0; i<2; i++) {
            for(int j=0; j<N; j++) 
                cin >> stck[i][j];
        }

        D[0][0] = stck[0][0]; D[1][0] = stck[1][0];
        D[0][1] = stck[0][1] + D[1][0];
        D[1][1] = stck[1][1] + D[0][0];
        //D[i][j] : i번째줄 j번째 원소를 골랐을 때까지 왼쪽에서부터 최대 점수
        for(int j=2; j<N; j++) {
            D[0][j] = stck[0][j] + max(D[1][j-1], D[1][j-2]);
            D[1][j] = stck[1][j] + max(D[0][j-1], D[0][j-2]);
        }
        
        cout << max(D[0][N-1], D[1][N-1]) << "\n";

        T--;
    }
}