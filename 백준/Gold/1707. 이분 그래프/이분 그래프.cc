// graph theory - gold4
// 23.07.25

#include <iostream>
#include <vector>

bool isBipartite;
using namespace std;

vector<int> check;
vector<bool> visited;
vector<vector<int>> graph;

void DFS(int node);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, V, E;
    
    cin >> T;
    while(T>0) {

        cin >> V >> E;
        check.resize(V+1);
        graph.resize(V+1);
        visited.resize(V+1);
        isBipartite = true;

        for(int i=0; i<E; i++) {
            int A, B;
            cin >> A >> B;
            graph[A].push_back(B);
            graph[B].push_back(A);
        }

        for(int i=1; i<=V; i++) {
            if (isBipartite) DFS(i);
            else break;
        }

        if (isBipartite) cout << "YES\n";
        else cout << "NO\n";

        for(int i=1; i<=V; i++) {
            check[i] = 0;
            graph[i].clear();
            visited[i] = false;
        }

        T--;
    }
    return 0;
}

void DFS(int node)
{
    visited[node] = true;

    for(int i : graph[node]) {  // for adjacent nodes
        if(!visited[i]) {       // if not visited, update group
            check[i] = (check[node]+1)%2;
            DFS(i);
        }                       // if visited and in same group
        else if(check[node] == check[i]) {
            isBipartite = false;
        }
    }
    //visited[node] = false;
}