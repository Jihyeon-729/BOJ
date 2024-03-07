#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq; // 내림차순
    priority_queue<int, vector<int>, greater<int>> rpq; // 오름차순
    
    int cnt = 0;
    for(auto op : operations) {
        int num; char cmd;
        istringstream iss(op);
        iss >> cmd >> num;
        
        if(cnt == 0) {
            while(!pq.empty()) pq.pop();
            while(!rpq.empty()) rpq.pop();
        }
        
        if(cmd == 'I') {
            pq.push(num);
            rpq.push(num);
            cnt++;
        } 
        else if (cmd == 'D') {
            if(num==1 && cnt>0) {
                pq.pop();
                cnt--;
            } else if (num==-1 && cnt>0) {
                rpq.pop();
                cnt--;
            }
        }
        
    }
    
    if(cnt == 0) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(pq.top());
        answer.push_back(rpq.top());
    }
    return answer;
}
