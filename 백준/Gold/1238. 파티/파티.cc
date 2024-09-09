#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define inf (~0u >> 2)
typedef pair<int, int> pii;

int n, m, x;
int minT[1001];
vector<pii> info[1001];

void init(void);
int dijkstra_to_x(int start);
void dijkstra_to_home(void);
void answer(void);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    for(int i=1; i<=n; i++) {
        minT[i] = dijkstra_to_x(i);
    }
    dijkstra_to_home();

    answer();

    return 0;
}

void init(void) {
    cin >> n >> m >> x;

    int a, b, t;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> t;
        info[a].push_back({b, t});  // 다음노드, 시간
    }

    for(int i=0; i<n; i++) {
        minT[i] = inf;
    }

    return;
}

int dijkstra_to_x(int start) {

    priority_queue<pii> pq;
    pq.push({0, start});  

    int timeto[1001];
    for(int i=1; i<=n; i++) {
        timeto[i] = inf;
    }
    timeto[start] = 0;  

    while(!pq.empty()) {
        int ctime = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for(int i=0; i<info[curr].size(); i++) {
            int next = info[curr][i].first;
            int ntime = info[curr][i].second;
            
            int etime = ctime+ntime;    //expected time
            if(timeto[next] <= etime) continue;

            timeto[next] = etime;
            pq.push({-etime, next});
        }
    }

    return timeto[x];
}

void dijkstra_to_home(void) {

    priority_queue<pii> pq;
    pq.push({0, x});

    int timeto[1001];
    for (int i = 1; i <= n; i++)
    {
        timeto[i] = inf;
    }
    timeto[x] = 0;

    while (!pq.empty())
    {
        int ctime = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for (int i = 0; i < info[curr].size(); i++)
        {
            int next = info[curr][i].first;
            int ntime = info[curr][i].second;

            int etime = ctime + ntime; // expected time
            if (timeto[next] <= etime)
                continue;

            timeto[next] = etime;
            pq.push({-etime, next});
        }
    }

    for(int i=1; i<=n; i++) {
        minT[i] += timeto[i];
    }
}

void answer(void) {
    int maxT = -1;
    for(int i=1; i<=n; i++) {
        if(minT[i] > maxT)
            maxT = minT[i];
    }
    cout << maxT << "\n";
    return;
}