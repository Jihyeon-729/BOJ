// DP - silver1
// 23.08.10

#include <iostream>

using namespace std;

int D[100001];

int main()
{
    int N;
    cin >> N;

    int D[100001];    
    D[0] = 1; D[1] = 3;
    for (int i = 2; i <= N; i++)
        D[i] = (D[i - 1] * 2 + D[i - 2]) % 9901;
    
    cout << D[N];
}