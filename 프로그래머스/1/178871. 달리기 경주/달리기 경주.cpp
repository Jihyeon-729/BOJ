#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string swap(vector<string> &answer, int front, int next) {
    string passed;
    passed = answer[front];
    answer[front] = answer[next];
    answer[next] = passed;
    return passed;
}

vector<string> solution(vector<string> players, vector<string> callings) {
    string passing, passed;
    vector<string> answer;
    map<string, int> rank;

    // 선수이름:등수 맵셋 생성
    for(int i=0; i<players.size(); i++) {
        rank[players[i]] = i;
    }
    
    // 등수:선수이름 벡터
    answer = players;
    for(int i=0; i<callings.size(); i++) {
        passing = callings[i];
        passed = swap(answer, rank[passing]-1, rank[passing]);
        rank[passed] += 1;
        rank[passing] -= 1;
    }
    
    return answer;
}