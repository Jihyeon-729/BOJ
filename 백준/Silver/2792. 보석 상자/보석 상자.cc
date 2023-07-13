// binary search - silver1
// 23.07.12

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, c;
    int l, r, m, cnt;
    int minGem = 1000000001;
    vector<int> gem;

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        cin >> c;
        gem.push_back(c);
    }

    sort(gem.begin(), gem.end());
    l = 1; r = gem[M-1];
    while(l <= r) {
        m = (l+r)/2;
        cnt = 0;
        for(int i=0; i<M; i++) {
            cnt += gem[i]/m;
            if(gem[i]%m != 0) {
                cnt++;
            }
        }
        if(cnt > N) {
            l = m+1;
        }
        else {
            r = m-1;
            if (minGem > m)
                minGem = m;
        }
        //  cout << "l, r = " << l << ", " << r << "\n";
        //  cout << "cnt = " << cnt << ", minGem = " << minGem << "\n";

    }
    cout << minGem << "\n";
    return 0;
}