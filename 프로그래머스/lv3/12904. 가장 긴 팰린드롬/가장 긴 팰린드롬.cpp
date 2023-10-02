#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define max(a, b) a>b? a:b

int solution(string s)
{
    int answer=0;
    
    // ex. abcddba
    /*
    for(int i=0; i<s.size(); i++) {
        for(int j=s.size()-1; j>=i; j--) {
            if(j-i+1 > answer) {
                string tmp, rev;
                tmp.assign(s.begin()+i, s.begin()+j+1);
                rev = tmp;
                reverse(rev.begin(), rev.end());
                if(tmp == rev) answer = max(answer, j-i+1);
            }
            else break;
        }
    }
    */
    for(int i=0; i<s.size(); i++) {
        int left, right;
        // odd
        left = right = i;
        while(0<=left && right<s.size()) {
            if(s[left] != s[right]) break;
            left--; right++;
        }
        answer = max(answer, right-left-1);
        // even
        left = i-1; right = i;
        while(0<=left && right<s.size()) {
            if(s[left] != s[right]) break;
            left--; right++;
        }
        answer = max(answer, right-left-1);
    }

    return answer;
}