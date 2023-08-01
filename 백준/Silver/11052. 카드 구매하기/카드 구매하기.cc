#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    int A[1001];
    int D[1001];

    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> A[i];
    A[0] = 0;

    D[1] = A[1];
    for(int i=2; i<=N; i++) {
        int MaxVal = A[i];
        for(int j=1; j<=(i-j); j++) {
            MaxVal = max(MaxVal, D[j]+D[i-j]);
        }
        D[i] = MaxVal;
        // cout << "D[" << i << "]=" << D[i] << "\n";
    }

    cout << D[N] << "\n";
    return 0;
}