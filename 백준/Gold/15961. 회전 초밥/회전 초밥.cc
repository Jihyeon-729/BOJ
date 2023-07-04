// sliding window - gold4
// 23.07.04

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int rail[6000000];
int eaten[3001];

int main(void)
{
    int N, d, k, c;
    int start, end, cnt, max;

    cin >> N >> d >> k >> c;
    for(int i=0; i<N; i++) {
        cin >> rail[i];
        rail[i+N] = rail[i];
    }

    start = 0; end = k-1;
    cnt = 0; max = -1;
    eaten[c] = 1;
    for(int i=0; i<k; i++) {
        eaten[rail[i]]++;
    }
    for(int i=0; i<=d; i++) {
        if(eaten[i]!=0)
            cnt++;
    }

    while(start < N) {
        if (cnt > max) max = cnt;
        if (eaten[rail[start]] == 1)
            cnt--;
        eaten[rail[start]]--;
        start++; end++;
        if (eaten[rail[end]] == 0)
            cnt++;
        eaten[rail[end]]++;
    }
    cout << max << "\n";
}