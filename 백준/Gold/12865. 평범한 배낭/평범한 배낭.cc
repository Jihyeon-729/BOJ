#include <iostream>
#include <algorithm>

using namespace std;

int D[101][100001];
int W[101];
int V[101];

int main(void)
{
    int N, K;

    cin >> N >> K;
    for(int i=1; i<=N; i++) {
        cin >> W[i] >> V[i];
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            if(j<W[i]) D[i][j] = D[i-1][j];
            else D[i][j] = max(D[i-1][j], D[i-1][j-W[i]]+V[i]);
        }
    }

    cout << D[N][K] << "\n";

    return 0;
}