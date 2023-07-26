// DP - silver3
// 23.07.26

#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
    int N;
    vector<int> T, P, D;

    cin >> N;
    T.resize(N+1);
    P.resize(N+1);
    D.resize(N+2); fill(D.begin(), D.end(), 0);

    for(int i=1; i<=N; i++) {
        cin >> T[i] >> P[i];
    }

    // for(int i=0; i<D.size(); i++) {
    //     cout << i << "\t";
    // } cout << "\n";

    D[N+1] = 0;
    for(int i=N; i>0; i--) {
        int enddate = i+T[i];
        if(enddate > N+1) D[i] = D[i+1];
        else D[i] = max(D[i+1], P[i]+D[enddate]);
        // for(int j=0; j<D.size(); j++) {
        //     cout << D[j] << "\t";
        // }
        // cout << "\n";
    }

    cout << D[1] << "\n";

    return 0;
}