// stack - gold4
// 23.07.08

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long int lli;

int main(void)
{
    int N;
    lli n, x, y, sum;
    vector<int> v;
    priority_queue<lli, vector<lli>, greater<lli> > pq;
    // 반례 : 10 15 20 23 -> 20 23 25 -> 25 43 -> 68

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> n;
        pq.push(n);
    }

    sum = 0;
    while(pq.size() > 1) {
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();
        pq.push(x+y);
        sum += (x+y);
    }
    
    // cout << pq.top() << "\n";

    cout << sum << "\n";
    return 0;
}