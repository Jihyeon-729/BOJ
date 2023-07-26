// DP - silver3
// 23.07.26

#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    long D[91][2] = {0, };
    D[1][0] = 0; D[1][1] = 1;
    for(int i=2; i<=N; i++) {
        D[i][0] = D[i-1][0] + D[i-1][1];
        D[i][1] = D[i-1][0];
        // cout << D[i][0] << "\t" << D[i][1] << "\n";
    }

    cout << D[N][0] + D[N][1] << "\n";
    return 0;
}