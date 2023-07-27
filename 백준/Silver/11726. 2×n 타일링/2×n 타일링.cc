// DP - silver3
// 23.07.27

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> D(N+1);

    D[1] = 1; D[2] = 2;
    for(int i=3; i<=N; i++) {
        D[i] = (D[i-1] + D[i-2]) % 10007;
    }
    cout << D[N] << "\n";
    return 0;
}
