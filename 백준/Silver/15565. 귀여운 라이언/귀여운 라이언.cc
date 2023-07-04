// sliding window - silver1
// 23.07.04

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N, K;
    int n, start, end, min;
    int cnt[3] = {0, };
    vector<int> v;

    cin >> N >> K;
    for(int i=0; i<N; i++) {
        cin >> n;
        v.push_back(n);
    }

    min = N+1;
    start=0; end=K-1;
    for(int i=start; i<=end; i++) {
        cnt[v[i]]++;
    }

    // else
    while(end<N) {
        // cout << cnt[1] << " "<< cnt[2] << "\n";
        if (cnt[1] >= K) {
            if(min > (end-start+1))
                min = (end-start+1);
                if(min == K) break;
            cnt[v[start]]--;
            start++; 
        }
        else {
            end++;
            cnt[v[end]]++;
        }
    }
    if (min == N+1) min = -1;
    
    cout << min << "\n";
    return 0;
}