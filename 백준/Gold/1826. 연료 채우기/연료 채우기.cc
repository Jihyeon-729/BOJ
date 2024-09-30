#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, a, b, l, p;
    int answer = 0;

    vector<pii> jys;            // 주유소 ({거리, 연료량})

    // 주유소 정보 입력 및 가까운순 정렬
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        jys.push_back({a, b});
    }    
    sort(jys.begin(), jys.end());
    
    // 마을 거리(필요 연료량), 출발할때 연료량 입력
    cin >> l >> p;
    priority_queue<int> pq;

    // 주행정보 초기화
    int cur_idx = 0;
    int cur_gas = p;    // 현재 기름으로 도달할수 있는 최대 위치

    // 주행 시작
    // 목적지 거리보다 연료량이 적으면 주유소 선택해야 함
    // 최소 횟수 구하려면 기름 많이 주는 주유소부터 선택
    while (cur_gas < l)
    {
        // 아직 탐색할 주유소 남아있을 때
        // 현재 연료(위치) 이전 주유소 가스량을 전부 저장
        while (cur_idx < n && jys[cur_idx].first <= cur_gas)
        {
            pq.push(jys[cur_idx].second);
            cur_idx++;
        }

        // 마을 도착 불가 (연료 부족)
        if (pq.empty()) {
            answer = -1;
            break;
        }

        // cur_gas다 쓰는 위치까지 도착했다고 가정
        cur_gas += pq.top();
        pq.pop();
        answer++;
    } 
    
    cout << answer << "\n";
    
    return 0;
}
