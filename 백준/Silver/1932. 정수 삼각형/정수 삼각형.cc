/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// DP = silver1
// 23.07.30

#include <iostream>

using namespace std;

long tri[501][501];
long D[501][501];

int main()
{
    int N;
    long answer = -1;
    cin >> N;
    
    tri[0][0] = 0;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<i; j++) {
            cin >> tri[i][j];
        }
    }
    
    for(int i=1; i<=N; i++) {
        tri[i][0] += tri[i-1][0];
        for(int j=1; j<i; j++) {
            tri[i][j] += max(tri[i-1][j-1], tri[i-1][j]);
        }
        tri[i][i-1] += tri[i-1][i-1];
    }
    
    // for(int i=1; i<=N; i++) {
    //     for(int j=0; j<i; j++) {
    //         cout << tri[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    for(int i=0; i<N; i++) {
        answer = max(answer, tri[N][i]);
    }
    
    cout << answer << "\n";

    return 0;
}
