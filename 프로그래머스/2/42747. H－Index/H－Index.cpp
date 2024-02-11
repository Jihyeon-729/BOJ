#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int n = citations.size();   //n: 과학자가 발표한 논문 수 (1~1000)
    int h = 0;
    
    // 0 1 3 5 6
    // 0번 이상 인용된 논문이 0(citations[i])편 이상
    // 1번 이상 인용된 논문이 1편 이상
    // 3번 이상 인용된 논문이 3편 이상 (citations[i] <= n-i)
    // 5번 이상 인용된 논문이 5편 이상 (n-i)
    
    // 0 1 3 5 6 7 8
    
    sort(citations.begin(), citations.end());
    for (int i=0; i<n; i++) {
        if(citations[i] <= n-i) h = citations[i];
        else {
            // h와 citations[i] 사이의 최대 h-index 찾기
            int idx = i;
            int newh = h+1;
            while (newh <= (n-idx)) {
                //cout << "before: " << newh << "<=" << n-idx << "\n";
                newh++;
                if(newh >= citations[idx]) idx++;
                //cout << "after: newh " << newh << "<=" << n-idx << "\n"; 
            }
            h = newh-1;
            break;
        }
    }
    
    return h;
}