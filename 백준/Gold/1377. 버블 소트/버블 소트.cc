// sort(bubble) - gold2
// 23.07.07

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main(void)
{
    int N, n, ans;
    vector<pair<int, int> > v;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> n;
        v.push_back(make_pair(n, i));
    }

    sort(v.begin(), v.end());

    ans = v[0].second;
    for (int i=0; i<N; i++) {
        v[i].second -= i;
        ans = max(ans, v[i].second);
    }    
    cout << ans+1 << "\n";

    return 0;
}