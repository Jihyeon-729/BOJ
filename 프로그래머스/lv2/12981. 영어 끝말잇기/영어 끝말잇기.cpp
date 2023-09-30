#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    bool fail = false;
    vector<int> answer;
    
    for(int i=1; i<words.size(); i++) {
        if (words[i][0] != words[i-1][words[i-1].size()-1]) {
            return {(i%n)+1, (i/n)+1};
        }
        for(int j=0; j<i; j++) {
            if(words[i] == words[j]) {
                return {(i%n)+1, (i/n)+1};
            }
        }
    }
    
    return {0, 0};
}