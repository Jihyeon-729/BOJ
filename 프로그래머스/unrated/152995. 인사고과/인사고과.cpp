#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare1(vector<int> &a, vector<int> &b) {
    if(a[0] == b[0]) return a[1]<b[1];
    else return a[0]>b[0];
}

bool compare2(vector<int> &a, vector<int> &b) {
    return a[0]+a[1] > b[0]+b[1];
}

int solution(vector<vector<int>> scores) {
    int answer = 0, w1, w2, wanho, sum;
    bool noBonus = false;
    vector<vector<int>> newsc;
    
    w1 = scores[0][0]; w2 = scores[0][1];
    wanho = scores[0][0] + scores[0][1];
    
    for(int i=1; i<scores.size(); i++) {
        sum = scores[i][0]+scores[i][1];
        if(sum > wanho)
            newsc.push_back(scores[i]);
    }
    newsc.push_back({w1, w2});
    
    sort(newsc.begin(), newsc.end(), compare1);
    
    for(int i=0; i<newsc.size(); i++) {
        for(int j=i+1; j<newsc.size(); j++) {
            if(newsc[i][0]!=newsc[j][0] && newsc[i][1]>newsc[j][1]) {
                if(newsc[j][0] == w1 && newsc[j][1] == w2) return -1;
                else {
                    newsc[j][0] = 0; newsc[j][1] = 0;
                }
            }
        }
    }
    
    sort(newsc.begin(), newsc.end(), compare2);
    
    /*
    for(int i=0; i<newsc.size(); i++) {
        cout << newsc[i][0] << " " << newsc[i][1] << "\n";
    }
    */
    
    for(int i=0; i<newsc.size(); i++) {
        if(newsc[i][0] == w1 && newsc[i][1] == w2) break;
        else answer++;
    }
    
    return answer+1;
}

/*
[[2,2,4,0],
 [1,4,5,1],
 [3,2,5,2],
 [3,2,5,3],
 [2,1,3,4]]

[[1,4,5,1],
 [2,1,3,4],
 [2,2,4,0],
 [3,2,5,2],
 [3,2,5,3]]

[[1,4,5,1],
 [3,2,5,2],
 [3,2,5,3],
 [2,2,4,0],
 [2,1,3,4]]
*/