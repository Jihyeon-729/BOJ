#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    int sbdiff = 'a'-'A';
    string token = "";
    string answer = "";
    istringstream iss(s);
    while(getline(iss, token, ' ')) {
        // 첫 문자가 소문자라면
        if('a'<=token[0] && token[0] <= 'z') {
            token[0] -= sbdiff;
        }
        // 다음 문자들 중 대문자가 있다면
        for(int i=1; i<token.size(); i++) {
            if('A'<=token[i] && token[i] <= 'Z')
                token[i] += sbdiff;
        }
        answer += token;
        answer += " ";
        token = "";
    }
    
    while(answer.size() > s.size()) {
        answer.erase(answer.end()-1);
    }
    return answer;
}