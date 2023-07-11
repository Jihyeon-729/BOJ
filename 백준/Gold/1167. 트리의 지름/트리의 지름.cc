// bfs - silver1
// 23.07.10

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef long long int lli;
typedef pair<int, int> edge;

vector<bool> visited;
vector<int> maxDist;
vector<vector<edge>> tree;

void BFS(int from);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int V, from, to, dist, Max;

    cin >> V;
    tree.resize(V+1);

    visited = vector<bool>(V+1, false);
    maxDist = vector<int>(V+1, 0);
    for(int i=1; i<=V; i++) {
        cin >> from;
        while (true) {
            cin >> to;
            if(to == -1) break;
            else {
                cin >> dist;
                tree[from].push_back(edge(to, dist));
            }
        }
    }

    BFS(1);

    Max = 1;
    for(int i=2; i<=V; i++) {
        if (maxDist[Max] < maxDist[i])
            Max = i;
    }

    fill(visited.begin(), visited.end(), false);
    fill(maxDist.begin(), maxDist.end(), 0);

    BFS(Max);

    sort(maxDist.begin(), maxDist.end());
    cout << maxDist[V] << "\n";
    
    return 0;
}

void BFS(int from)
{
    int curr, next, dist;

    queue<int> q;
    q.push(from);
    visited[from] = true;

    while (!q.empty()) {
        curr = q.front();
        q.pop();
        for(int i=0; i<tree[curr].size(); i++) {
            next = tree[curr][i].first;
            dist = tree[curr][i].second;
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
                maxDist[next] = maxDist[curr] + dist;
            }
        }
    }
}