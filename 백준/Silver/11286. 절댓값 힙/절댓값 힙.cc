// stack - silver1
// 23.07.07

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    int N, x;
    pair<int, int> pii;
    vector<int> v;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> x;
        if(x==0) {
            if(!pq.empty()) {
                v.push_back(pq.top().second);
                pq.pop();
            }
            else
                v.push_back(0);
        }
        else {
            pii = make_pair(abs(x), x);
            pq.push(pii);
        }
    }

    for(int i=0; i<v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}