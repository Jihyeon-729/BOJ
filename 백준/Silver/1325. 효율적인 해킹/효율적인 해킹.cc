// graph theory - silver1
// 23.07.25

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, A, B;
vector<int> answer;
vector<bool> visited;
vector<vector<int>> trusted;

void BFS(int node);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, A, B;
    int Max;

    cin >> N >> M;
    answer.resize(N+1);
    trusted.resize(N+1);
    visited.resize(N+1);

    for(int i=0; i<M; i++) {
        cin >> A >> B;
        trusted[A].push_back(B);
    }

    fill(answer.begin(), answer.end(), 0);
    for(int i=1; i<=N; i++) {
        fill(visited.begin(), visited.end(), false);
        BFS(i);
    }

    Max = *max_element(answer.begin(), answer.end());

    // for(int i=1; i<=N; i++) {
    //     cout << answer[i] << " ";
    // }
    // cout << "\n";

    for(int i=1; i<=N; i++) {
        if(answer[i] == Max)
            cout << i << " ";
    }
    cout << "\n";

    return 0;
}

void BFS(int node)
{
    int currnode;
    queue<int> q;

    q.push(node);
    visited[node] = true;

    while(!q.empty()) {
        currnode = q.front();
        q.pop();
        for(int i : trusted[currnode]) {
            if(!visited[i]) {
                visited[i] = true;
                answer[i]++;
                q.push(i);

            }
        }
    }
}