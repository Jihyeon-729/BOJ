// DP = silver1
// 23.07.30

#include <iostream>

using namespace std;

long house[1001][3];

int main()
{
    int N, r, g, b;
    long answer;
    cin >> N;
    
    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;
    for(int i=1; i<=N; i++) {
        cin >> r >> g >> b;
        // cin >> house[i][0] >> house[i][1] >> house[i][2];
        house[i][0] = min(house[i-1][1],house[i-1][2]) + r;
        house[i][1] = min(house[i-1][0],house[i-1][2]) + g;
        house[i][2] = min(house[i-1][1],house[i-1][0]) + b;
    }
    
    answer = min(house[N][0], min(house[N][1], house[N][2]));
    cout << answer << "\n";

    return 0;
}