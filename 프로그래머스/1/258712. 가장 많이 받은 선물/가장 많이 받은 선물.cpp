#include <sstream>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int table[50][50];
    int index[50][3];
    map<string, int> Map;
    
    // 초기화
    memset(index, 0, sizeof(index));
    memset(table, 0, sizeof(table));
    for(int i=0; i<friends.size(); i++)
        Map[friends[i]] = i;
    
    // 주고받은 선물 표
    for(int i=0; i<gifts.size(); i++) {
        string token;
        vector<string> gift;
        istringstream iss(gifts[i]);
        while(getline(iss, token, ' ')) 
            gift.push_back(token);
        int from = Map[gift[0]];
        int to = Map[gift[1]];
        table[from][to] += 1;
    }
    
    // 선물 지수 표
    // 준 선물
    for(int i=0; i<friends.size(); i++) {
        int given = 0;
        for(int j=0; j<friends.size(); j++)
            given += table[i][j];
        index[i][0] = given;
    }
    // 받은 선물
    for(int i=0; i<friends.size(); i++) {
        int received = 0;
        for(int j=0; j<friends.size(); j++)
            received += table[j][i];
        index[i][1] = received;
    }
    // 선물 지수
    for(int i=0; i<friends.size(); i++)
        index[i][2] = index[i][0] - index[i][1];
    
    
    for(int i=0; i<friends.size(); i++) {
        int present = 0;
        for(int j=0; j<friends.size(); j++) {
            //table[i][j] : i가 j에게 준 선물 수
            if(i!=j) {
                if(table[i][j]>table[j][i]) present++;
                else if (table[i][j]==0 && table[j][i]==0) {
                    if (index[i][2]>index[j][2]) present++;
                }
                else if (table[i][j]==table[j][i]){
                    if (index[i][2]>index[j][2]) present++;
                }
            }
        }
        answer = max(answer, present);
    }
    
    return answer;
}