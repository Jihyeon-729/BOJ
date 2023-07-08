// two pointers - silver1
// 23.07.08

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K, n;
    int start, end, ans;
    int cnt[100001] = {0, };
    vector<int> seq;

    cin >> N >> K;
    for(int i=0; i<N; i++) {
        cin >> n;
        seq.push_back(n);
    }

    ans = 0;
    start = end = 0;
    while(start<=end && end<N){
        if(cnt[seq[end]] < K) {
			cnt[seq[end++]]++;
			ans = max(ans, end - start);
        }
		else if (cnt[seq[end]] == K) {
			cnt[seq[start++]]--;
		}
    }

    cout << ans << "\n";

    return 0;
}