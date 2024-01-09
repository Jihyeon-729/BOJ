#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[201];

void DFS(int from, int n, vector<vector<int>> computers);

int solution(int n, vector<vector<int>> computers) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int ans = 0;
    for(int i=0; i<n; i++) {
        // 노드 i 체크한 적 없으면
        if(!visited[i]) {
            for(int j=0; j<n; j++) {
                if (i==j) continue;
                // 연결된 노드 중 체크한 적 없는 노드 탐색
                if (!visited[j] && computers[i][j]==1) DFS(j, n, computers);
            }
            ans++;
        }
    }
    
    return ans;
}

void DFS(int from, int n, vector<vector<int>> computers) {
    visited[from] = true;
    
    for(int i=0; i<n; i++) {
        if(from == i) continue;
        if(!visited[i] && computers[from][i]==1) DFS(i, n, computers);
    }
}

/*
void DFS(int n, int from, int cnt, vector<int> &checked, vector<vector<int>> computers);

int solution(int n, vector<vector<int>> computers) {
    int answer, count = 1;
    vector<int> checked(n);
    
    for(int c=0; c<n; c++) {
        if(!checked[c]) {
            DFS(n, c, count, checked, computers);
            count++;
        }
    }
    answer = count-1;
    
    return answer;
}

void DFS(int n, int from, int cnt, vector<int> &checked, vector<vector<int>> computers)
{
    checked[from] = cnt;
    for(int to=0; to<n; to++) {
        // 컴 from과 to가 같지 않고, to 연결 확인한 적 없고, 
        // 확인해봤더니 from~to 연결이 존재한다면 DFS
        if (from!=to && !checked[to] && computers[from][to] == 1) {
                DFS(n, to, cnt, checked, computers);
        }
    }
    return;
}
*/