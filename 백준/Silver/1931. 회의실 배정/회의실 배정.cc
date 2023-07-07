// sorting - silver1
// 23.07.07

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main(void)
{
    int N, start, end, i, cnt;
    pair<int, int> info;
    vector<pair<int, int> > table;

    cin >> N;
    for(i=0; i<N; i++) {
        cin >> start >> end;
        info = make_pair(start, end);
        table.push_back(info);
    }

    sort(table.begin(), table.end(), compare);

    i=1; cnt=1;
    end = table[0].second;
    while (i<N) {
        if(table[i].first >= end) {
            end = table[i].second; cnt++;
        }
        i++;
    }

    cout << cnt << "\n";

    return 0;
}