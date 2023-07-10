// dfs - gold5
// 23.07.10

#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool answer = false;
bool visited[2000];
vector<vector<int> > friends;

void DFS(int from, int depth);

int main(void)
{
    int x, y;

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        vector<int> v;
        friends.push_back(v);
    }
    for(int i=0; i<N; i++) {
        visited[i] = false;
    }
    for(int i=0; i<M; i++) {
        cin >> x >> y;
        friends[x].push_back(y);
        friends[y].push_back(x);
    }

    for(int i=0; i<N; i++) {
        DFS(i, 1);
    }

    cout << answer << "\n";

    return 0;
}

void DFS(int from, int depth) {
    int next;
    if(depth == 5) {
        answer = true;
        return;
    }

    visited[from] = true;
    for(int i=0; i<friends[from].size() && !answer; i++) {
        next = friends[from][i];
        if(!visited[next])
            DFS(next, depth+1);
    }
    visited[from] = false;

    return;
}