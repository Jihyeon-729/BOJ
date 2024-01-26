#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int n=1;
    int answer=0;
    int limit=0;
    
    if(s[0]=='+' || s[0]=='-') 
        limit = 1;
    else limit = 0;

    for(int i=s.size()-1; i>=limit; i--) {
        answer += n*(s[i]-'0');
        n *= 10;
    }
    
    if(s[0] == '-') return answer*(-1);
    else return answer;
}