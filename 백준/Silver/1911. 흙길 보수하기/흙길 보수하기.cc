// sort - gold4
// 23.07.09

#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main (void)
{
    int N, L, answer;
    int start, end, pool; // pool start, end, size
    int from, to;   // recently, lastly covered idx
    int quot, remd; // quotient, remainder
    vector<pair<int, int> > v;

    cin >> N >> L;
    for(int i=0; i<N; i++) {
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end());

    to = 0;
    answer = 0;
    for(int i=0; i<N; i++) {
        if(v[i].first > to)
            to = v[i].first;

        while(to < v[i].second) {
            to += L;
            answer++;
        }
    }

    cout << answer << "\n";

    return 0;
}
