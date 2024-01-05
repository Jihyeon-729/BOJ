#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    queue<int> q;
    vector<int> dist(n+1, -1);
    vector<vector<int>> graph(n+1);
    
    for (auto e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    dist[1] = 1;
    q.push(1);
    while(!q.empty())
    {
        int p = q.front(); q.pop();
        for (auto node : graph[p]) {
            if (dist[node] == -1) {
                dist[node] = dist[p]+1;
                q.push(node);
            }
        }
    }
    int maxDist = *max_element(dist.begin(), dist.end());
    for (auto d : dist) {
        if (d == maxDist) answer++;
    }
    
    return answer;
}