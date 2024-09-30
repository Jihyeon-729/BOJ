#include <iostream>
#include <cstring>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#include <utility>

#define INF 0x3f3f3f3f;

using namespace std;

typedef pair<int, int> pii;

int n, m, gas;
int board[21][21];
int dist[21][21];
int ck[21][21];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int taxiRow, taxiCol;

typedef struct {
    int startRow, startCol;
    int endRow, endCol;
    int distance;
} Customer;

vector <Customer> customerInfo;

bool cmp(Customer a, Customer b){
    if(a.distance == b.distance){
        if(a.startRow == b.startRow)
            return a.startCol < b.startCol;
        return a.startRow < b.startRow;
    }
    return a.distance < b.distance;
}

void init(void);
bool to_cust(void);
bool to_dest(void);
void update_dist(void);

int main(void) 
{    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    while(customerInfo.size()){
        if(!to_cust()) {
            cout << "-1\n"; return 0;
        }
        else if (!to_dest()) {
            cout << "-1\n"; return 0;
        };
        customerInfo.erase(customerInfo.begin());
    }
    cout << gas;

    return 0;
}

void init(void)
{
    cin >> n >> m >> gas;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }
    cin >> taxiRow >> taxiCol;
    for(int i = 1; i <= m; i++){
        Customer customer;
        cin >> customer.startRow >> customer.startCol >> customer.endRow >> customer.endCol;
        customerInfo.push_back(customer);
    }
}

bool to_cust(void) 
{
    update_dist();
    for (int i = 0; i < customerInfo.size(); i++)
        customerInfo[i].distance = dist[customerInfo[i].startRow][customerInfo[i].startCol];
    sort(customerInfo.begin(), customerInfo.end(), cmp);

    // 
    if(!customerInfo[0].distance) {
        if(taxiRow != customerInfo[0].startRow || taxiCol != customerInfo[0].startCol)
            return false;
    }
    
    // 연료 < 가장 가까운 고객까지 거리
    if(customerInfo[0].distance > gas) 
        return false;

    // 택시 정보 갱신
    taxiRow = customerInfo[0].startRow;
    taxiCol = customerInfo[0].startCol;
    gas -= customerInfo[0].distance; 

    return true;
}

bool to_dest(void) 
{
    update_dist();
    for (int i = 0; i < customerInfo.size(); i++)
        customerInfo[i].distance = dist[customerInfo[i].endRow][customerInfo[i].endCol];

    if(!customerInfo[0].distance) {
        if(taxiRow != customerInfo[0].startRow || taxiCol != customerInfo[0].startCol)
            return false;
    }
    if(customerInfo[0].distance > gas) 
        return false;

    taxiRow = customerInfo[0].endRow;
    taxiCol = customerInfo[0].endCol;
    
    gas += customerInfo[0].distance; 
    return true;
}

void update_dist(void)
{
    memset(ck, 0, sizeof(ck));
    memset(dist, 0, sizeof(dist));
    
    queue<pii> q;
    q.push({taxiRow, taxiCol});
    ck[taxiRow][taxiCol] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (1 > nx || nx > n || 1 > ny || ny > n)
                continue;
            if (board[nx][ny] == 1 || ck[nx][ny])
                continue;
            ck[nx][ny] = 1;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}