#include <string>
#include <vector>
#include <algorithm>
#include <queue>

// 다시 풀어보기!

using namespace std;

// cases[0][1]=3 : 0번째 경우의 수에서 1번 유형 멘토는 3명
vector<vector<int>> cases;
/*
void permutation(int idx, int left, vector<int> &cs);
int calculate(vector<int> &cs, vector<vector<int>> &reqs);
*/


void permutation(int idx, int left, vector<int> &cs)
{
    if(left <= 0) {
        cases.push_back(cs);
    }
    else {
        for(int i=idx; i<=cs.size(); i++) {
            cs[i]++;
            permutation(i, left-1, cs);
            cs[i]--;
        }
    }
    return;
}

int calculate(vector<int> &cs, vector<vector<int>> &reqs)
{
    int waiting = 0;
    int arrival, duration, type, closest;
    priority_queue<int, vector<int>, greater<int>> pq[cs.size()];
    
    for(int i=1; i<cs.size(); i++) {
        for(int j=0; j<cs[i]; j++)
            pq[i].push(0);
    }
    
    for(auto req : reqs) {
        arrival = req[0]; duration = req[1]; type = req[2];
        
        closest = pq[type].top(); 
        pq[type].pop();
        
        if(closest <= arrival)
            pq[type].push(arrival + duration);
        else {
            waiting += (closest - arrival);
            pq[type].push(closest + duration);
        }
    }
    return waiting;    
}
int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 99999999, waiting;
    
    // 가능한 유형별 멘토 수 순열 만들기
    vector<int> cs(k+1, 1);
    permutation(1, n-k, cs);
    
    for(auto cs: cases) {
        waiting = calculate(cs, reqs);
        if(answer > waiting) answer = waiting;
    }
    
    return answer;
}