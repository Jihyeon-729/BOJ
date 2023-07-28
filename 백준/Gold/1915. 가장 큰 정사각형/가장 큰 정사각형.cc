/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// DP - gold4 (01915)
// 23.07.28

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int D[1001][1001];

int main()
{
    int n, m;
    string s;
    long Max = -1;
    
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> s;
        for(int j=1; j<=m; j++) {
            D[i][j] = s[j-1] - '0';
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if (D[i][j] == 1)
                D[i][j] = min(D[i-1][j-1], min(D[i][j-1], D[i-1][j])) + 1;
            if (Max < D[i][j])
                Max = D[i][j];
        }
    }
    cout << Max * Max << "\n";
    

    return 0;
}
