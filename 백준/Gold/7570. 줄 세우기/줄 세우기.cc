#include <iostream>
#include <algorithm>

using namespace std;

// 가장 큰 증가하는 부분수열의 크기
// https://beginthread.tistory.com/137

#define MAX 1000001

int N;
int LIS[MAX];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, maxlen = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n;
        LIS[n] = LIS[n - 1] + 1;
        maxlen = max(maxlen, LIS[n]);
    }

    cout << N - maxlen << "\n";

    return 0;
}