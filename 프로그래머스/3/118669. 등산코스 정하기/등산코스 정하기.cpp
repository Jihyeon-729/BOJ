#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer(2, -1);
    vector<vector<pair<int, int>>> map(n+1);
    vector<long long> distance(n+1, -1);
    vector<bool> isSummit(n+1, false);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    for(auto s : summits)
        isSummit[s] = true;
    for(const auto& p : paths) {
        map[p[0]].push_back({p[1],p[2]});
        map[p[1]].push_back({p[0],p[2]});
    }
    for(auto g : gates) {
        distance[g] = 0;
        pq.push({distance[g], g});
    }
    
    while(!pq.empty())
    {
        int curN = pq.top().second;
        int intensity = pq.top().first;
        pq.pop();
        
        if(answer[0] != -1 && answer[1] < intensity)
            continue;
            
        if(isSummit[curN]) {
            if(intensity < answer[1] || answer[0] == -1) {
                answer[0] = curN;
                answer[1] = intensity;
            }
            else if(intensity == answer[1] && curN < answer[0]) {
                answer[0] = curN;
            }
            
            continue;
        }
        
        for(int i = 0; i < map[curN].size(); ++i)
        {
            int nextN = map[curN][i].first;
            int nextIntensity = map[curN][i].second;
            nextIntensity = max(intensity, nextIntensity);
            
            if(distance[nextN] == -1 || nextIntensity < distance[nextN]) {
                distance[nextN] = nextIntensity;
                pq.push({nextIntensity, nextN});
            }
        }
    }

    
    return answer;
}

/*
bool isSummit[20001];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer(2, -1);
    vector<long long> intensity(n+1, -1);
    vector<vector<pair<int, int>>> graph(n+1);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    // 초기화
    for(auto summit : summits)
        isSummit[summit] = true;
    for(auto path : paths) {
        graph[path[0]].push_back({path[1],path[2]});
        graph[path[1]].push_back({path[0],path[2]});
    } 
    for(auto gate : gates) {
        intensity[gate] = 0;
        pq.push({intensity[gate], gate});
    }
    
    while(!pq.empty()) {
        int currI = pq.top().first;
        int currN = pq.top().second;
        pq.pop();
        
        if(answer[0] != -1 && answer[1] < currI) continue;

        if(isSummit[currN]) {
            if(currI < answer[1] || answer[0] == -1) {
                answer[0] = currN;
                answer[1] = currI;
            }
            else if(currI == answer[1] && currN < answer[0]) {
                answer[0] = currN;
            }
            continue;
        }
        
        for(int i = 0; i < graph[currN].size(); i++) {
            int nextN = graph[currN][i].first;
            int nextI = graph[currN][i].second;
            nextI = max(currI, nextI);
            
            if(intensity[nextN] == -1 || nextI < intensity[nextN]) {
                intensity[nextN] = nextI;
                pq.push({nextI, nextN});
            }
        }
    }
    
    return answer;
}
*/
/*
#define INF 10000001

int nodes;
int graph[20001][20001];    // 방향 없고 엣지 가중치는 있는 그래프
bool visited[20001];
bool isGate[20001];
bool isSummit[20001];

// from 지점에서 다음 갈 지점 탐색
int DFS(int prev, int curr, int summit)
{
    int intensity = INF, min_intensity = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    if(curr == summit) {
        //cout << "graph[" << summit << "][" << prev << "] : " << graph[summit][prev] << "\n";
        return graph[summit][prev];
    }
    
    // 방문했다고 표시
    visited[curr] = true;
    
    for(int nxt=1; nxt<=nodes; nxt++) {
        // 연결되어있고, 방문한 적 없고 
        // gate나 다른 summit에 해당되지 않는 노드의 경우 탐색 대상
        if(graph[curr][nxt] != INF && !visited[nxt]) {
            if(!isGate[nxt] && (!isSummit[nxt] || (isSummit[nxt] && nxt == summit))) {
                // ex. 2에서 출발 : [2, 4], [4, 5], [5, 3]
                pq.push({graph[curr][nxt], nxt});
            }
        }
    }
    
    while(!pq.empty()) {
        int next = pq.top().second; pq.pop();
        
        // 탐색할 엣지 가중치가 지금까지 나왔던 인텐시티보다 크면 탐색 중지 (인텐시티 불필요하게 증가)
        if(graph[curr][next] > intensity) break;
        
        // 탐색한 인접 엣지들 중 가중치 최소인 엣지 선택
        intensity = min(intensity, DFS(curr, next, summit));
    }
    // 현재레벨 -> 아래 레벨 엣지 가중치 vs 현재 노드->이전 노드 가중치 중 큰 값 선택 (intensity 저장)
    if(!isGate[curr])
        intensity = max(intensity, graph[curr][prev]);

    visited[curr] = false;    
    return intensity;
}

struct compare
{
    bool operator() (const vector<int> a, const vector<int> b)
    {
        if(a[2] > b[2]) return true;
        else if(a[2] == b[2]) {
            return a[1] > b[1];
        }
        else return false;
    }
};
struct compare
{
    bool operator() (const vector<int> a, const vector<int> b)
    {
        if(a[1] > b[1]) return true;
        else if(a[1] == b[1]) {
            return a[0] > b[0];
        }
        else return false;
    }
};

// n : 노드 개수 (5만 이하)
// paths.size() : 엣지 개수 (20만 이하)
// [i, j, w] -> w: 가중치값, 10,000,000(천만 이하)
// 출입구(여러개), 쉼터(여러개), 산봉우리(여러개)
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    priority_queue<vector<int>, vector<vector<int>>, compare> answer;
    
    nodes = n;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++)
            graph[i][j] = INF;
    }
    for(auto path : paths) {
        graph[path[0]][path[1]] = path[2]; 
        graph[path[1]][path[0]] = path[2];
    }
    for(auto gate : gates) {
        isGate[gate] = true;
    }
    for(auto summit : summits) {
        isSummit[summit] = true;
    }
    
    // 등산 코스의 인텐시티 : 해당 코스(네트워크)에 포함된 엣지 중 가장 큰 가중치값
    for(auto gate : gates) {
        for(auto summit : summits) {
            vector<int> v;
            //v.push_back(gate);
            v.push_back(summit); v.push_back(DFS(0, gate, summit));
            answer.push(v);
        }
    }
    //vector<int> tmp = answer.top();
    
    while(!answer.empty()) {
        cout << "[" << answer.top()[0] << ", " << answer.top()[1] << ", " << answer.top()[2] << "]\n";
        answer.pop();
    }
    
    // 리턴값 : 인텐시티 최소인 등산코스 산봉우리 번호, 인텐시티 최솟값
    return answer.top();
}
*/
