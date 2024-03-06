#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<string, int> gmap;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    int len = gems.size();
    for(int i=0; i<len; i++)
        gmap[gems[i]] = 0;
    int types = gmap.size();
    gmap.clear();
    
    int beg=0, end=0;
    int cnt = 1;
    gmap[gems[0]] = 1;
    
    answer.push_back(0);
    answer.push_back(len);
    
    while(end<len) {
        
        // 보석 종류 다 안 나온 경우
        if(cnt < types) {
            end++;
            
            // 배열 마지막까지 확인한 경우
            if(end == len) break;
            
            // 보석 확인한 경우
            if (gmap[gems[end]] == 0) cnt++; // new 보석
            gmap[gems[end]]++;
        }
        
        else {
            if (end-beg < answer[1]-answer[0]) {
                answer[0] = beg;
                answer[1] = end;
            }
            if(gmap[gems[beg]] == 1) cnt--;
            gmap[gems[beg]]--;
            beg++;
        }
    }
    
    answer[0]++;
    answer[1]++;
    
    return answer;
}
