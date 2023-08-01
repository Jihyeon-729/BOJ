// DP - silver1
// 23.08.01

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    int A[10001], D[10001];

    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> A[i];
    
    D[0]=0; D[1]=A[1]; D[2]=A[0]+A[1];
    for(int i=2; i<=N; i++) {
        D[i] = max({D[i-3]+A[i-1]+A[i], D[i-2] + A[i], D[i-1]});
    }

    cout << D[N] << "\n";

    return 0;
}