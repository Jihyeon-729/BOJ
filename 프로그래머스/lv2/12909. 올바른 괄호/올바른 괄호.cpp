#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> bracket;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    // cout << "Hello Cpp" << endl;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(')
            bracket.push('(');
        else if (s[i] == ')') {
            if(bracket.size() == 0) {
                answer = false; 
                return answer;            
            }
            else bracket.pop();
        }
    }
    
    if(bracket.size() != 0) 
        answer = false;
    
    return answer;
}