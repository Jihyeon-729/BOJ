#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    // 종류별 최대 1가지만 착용 (착용 안할 수도 있음)
    // 1 1 2, 1 1 3은 다른 착장
    // 최소 하루에 한 개의 의상은 입음
    map<string, vector<string>> smap;
    for(int i=0; i<clothes.size(); i++) {
        smap[clothes[i][1]].push_back(clothes[i][0]);
    }
    for(auto v : smap) {
        answer *= (v.second.size()+1);
    }
    answer--;
    
    return answer;
}