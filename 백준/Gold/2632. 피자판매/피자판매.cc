#include <iostream>

using namespace std;

long long answer;
int pizzasize, m, n;
int A[1001], B[1001];
long long sizecaseA[1000001], sizecaseB[1000001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> pizzasize >> m >> n;
    for(int i=0; i<m; i++) {
        cin >> A[i];
    } for (int i=0; i<n; i++) {
        cin >> B[i];
    }

    int sumA=0, sumB=0;
    sizecaseA[0] = 1;
    sizecaseB[0] = 1;

    // use every pieces
    for(int i=0; i<m; i++) {
        sumA += A[i];
    } sizecaseA[sumA]++;
    for(int i=0; i<n; i++) {
        sumB += B[i];
    } sizecaseB[sumB]++;
    
    // use some pieces (not all)
    for(int i=0; i<m; i++) {
        sumA = 0;
        for(int j=0; j<m-1; j++) {
            sumA += A[(i+j)%m];
            sizecaseA[sumA]++;
        }
    }
    for (int i=0; i<n; i++) {
        sumB = 0;
        for (int j=0; j<n-1; j++) {
            sumB += B[(i+j)%n];
            sizecaseB[sumB]++;
        }
    }

    for(int i=0; i<=pizzasize; i++) {
        answer += (sizecaseA[i] * sizecaseB[pizzasize-i]);
    } cout << answer << "\n";

    return 0;
}