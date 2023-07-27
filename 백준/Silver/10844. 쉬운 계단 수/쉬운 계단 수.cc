// DP - silver1
// 23.07.27

#include <iostream>

using namespace std;

int D[2][10];
long mod = 1000000000;

int main(void)
{
    int N, curr, last;
    long answer = 0;

    D[1][0] = 0;
    for(int i=1; i<10; i++) {
        D[1][i] = 1;
    }

    curr = 0;
    cin >> N;
    for(int i=2; i<=N; i++) {
        curr = i%2; last = (i-1)%2;
        D[curr][0] = D[last][1]%mod;
        for(int j=1; j<9; j++) {
            D[curr][j] = (D[last][j-1]+D[last][j+1])%mod;
        }
        D[curr][9] = D[last][8]%mod;

        // for(int j=0; j<10; j++)
        //     cout << D[curr][j] << "\t";
        // cout << "\n";
    }

    curr = N%2;
    for(int i=0; i<10; i++) {
        answer += D[curr][i];
    }
    cout << answer%mod << "\n";

    return 0;
}