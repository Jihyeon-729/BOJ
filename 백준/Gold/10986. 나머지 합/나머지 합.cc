// partial sum - gold3
// 23.07.02

#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long N, M, num, tot;
    long cnt[1000] = {0, };
    long psum[1000001] = {0, };

    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> num;
        psum[i] = (num+psum[i-1])%M;
        // (A+B)%C = ((A%C)+(B%C))%C
        cnt[psum[i]] += 1;
    }

    tot = cnt[0];
    for(int i=0; i<M; i++) {
        tot += (cnt[i]*(cnt[i]-1))/2;
    }
    cout << tot << "\n";

    return 0;
}