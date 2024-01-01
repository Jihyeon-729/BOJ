#include <string>
#include <vector>

using namespace std;

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