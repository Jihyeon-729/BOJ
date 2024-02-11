#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp (vector<int> &v1, vector<int> v2) {
    return v1.size() < v2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> vvec;
    // 1+2+..+500 = 250*501 = 125000+250 = 125250
    // 원소 하나짜리가 첫번째
    
    // O(n) -> n=백만
    // 첫번째 숫자부터 시작
    int idx = 2;
    while(idx<s.length()-1) {
        // ','가 나오면 다음 집합으로 점프
        if(s[idx] == ',') idx+=2;
        vector<int> vec;
        // 집합이 시작되면 '}'가 나올때까지 받기
        while(s[idx] != '}') {
            string num = "";
            // ','가 나올때까지 받기 (하나의 숫자)
            while(s[idx] != ',' && s[idx] != '}')
                num += s[idx++];            // 숫자값 읽기
            vec.push_back(stoi(num));       // 숫자값 저장
            if(s[idx] == ',') idx++;        // 집합 안 끝남
            else if(s[idx] == '}') break;   // 집합 끝남
        } idx++;
        sort(vec.begin(), vec.end());
        vvec.push_back(vec);
    }
    
    sort(vvec.begin(), vvec.end(), comp);
    
    /*
    for(int i=0; i<vvec.size(); i++) {
        for(auto n : vvec[i]) cout << n << " ";
        cout << "\n";
    }
    */
    
    answer.push_back(vvec[0][0]);
    // 차집합 원소 한개 넣기
    for(int i=0; i<vvec.size()-1; i++) {
        vector<int> buff(vvec[i].size() + vvec[i+1].size());
        auto iter = set_difference(vvec[i+1].begin(), vvec[i+1].end(), vvec[i].begin(), vvec[i].end(), buff.begin());
        buff.erase(iter, buff.end());
        answer.push_back(buff[0]);
    }
    
    
    return answer;
}