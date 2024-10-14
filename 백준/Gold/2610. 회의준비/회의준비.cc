#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 101
#define INF (~0u >> 2)

int N, M;
int dist[MAX][MAX];
bool adjacent[101][101], visited[101];
int passtime[101];
vector<int> leaders;

void init(void);
void get_dist(void);    // 모든 노드끼리의 최단거리 구하기
void get_mxtime(void);  // 의사전달시간 중 최댓값 구하기
int dfs(int curr);      // 대표 구하기
void get_lead(void);
void prt_answer(void);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    get_dist();
    get_mxtime();
    get_lead();
    prt_answer();

    return 0;
}

void init(void) {
    int a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adjacent[a][b] = true;
        adjacent[b][a] = true;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // 자기자신 / 인접노드 / 그외
            if (i == j) dist[i][j] = 0;
            else if (adjacent[i][j])
                dist[i][j] = 1;
            else dist[i][j] = INF;
        }
    }
}

// 플로이드-워셜
// 모든 노드로부터 다른 모든 노드까지의 거리 구하기
void get_dist(void)
{
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void get_mxtime()
{
    // i번째 사람이 리더라고 가정했을 때
    // 참석자들이 i로 의사전달할 때 걸리는 시간의
    // 최댓값을 구한다

    for (int i = 1; i <= N; i++) {
        int maxTime = -1;
        for (int j = 1; j <= N; j++) {
            if (dist[j][i] == INF) continue;
            maxTime = max(maxTime, dist[j][i]);
        }

        passtime[i] = maxTime;
    }
}

int dfs(int curr) {

    int lead = curr;
    visited[curr] = true;

    for (int next = 1; next <= N; next++)
    {
        if (!adjacent[curr][next]) continue;
        if(visited[next]) continue;

        // 인접하고 방문한 적 없는 경우에만 탐색
        int cand = dfs(next);
        if (passtime[cand] < passtime[lead])
            lead = cand;
    }

    return lead;
}

void get_lead(void)
{
    for (int i = 1; i <= N; i++) {
        if (!visited[i])
            leaders.push_back(dfs(i));
    }

    return;
}

void prt_answer(void) {
    sort(leaders.begin(), leaders.end());
    cout << leaders.size() << "\n";
    for (int i=0; i<leaders.size(); i++) {
        cout << leaders[i] << "\n";
    }
}
