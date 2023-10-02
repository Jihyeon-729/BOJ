#include <bits/stdc++.h>

using namespace std;

string toBinary(int n);

vector<int> solution(string s) {
    vector<int> answer;
    int cntBin, cntOne, cntZero;
    
    cntBin = 0; cntZero = 0;
    while(s != "1") {
        cntOne = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '1') cntOne++;
        }
        cntZero += (s.size()-cntOne);
        s = toBinary(cntOne);
        cntBin++;
    }
    return {cntBin, cntZero};
    
    //return answer;
}

string toBinary(int n) {
    string r;
    while(n!=0) {
        r = (n%2==0? "0":"1")+r; 
        n /= 2; }
    return r;
}