#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    int idx = -1;
    string answer = "";
    
    for(int i=0; i<number.size()-k; i++) {
        char maxNum = 0;
        for(int j=idx+1; j<=i+k; j++) {
            if(maxNum < number[j]) {
                maxNum = number[j];
                idx = j;
            }
        }
        answer += maxNum;
    }
    return answer;
}

/*
bool comp1(pair<int, int> &p1, pair<int, int> &p2)
{
    if(p1.second > p2.second) return true;
    else if (p1.second == p2.second && p1.first > p2.first) return true;
    else return false;
}
*/

/*
// 인덱스 l-k-1 이하, 가장 큰 수 (첫자리 지정)
for(int i=0; i<=k; i++) {
    if(maxNum < number[i]-'0') {
        maxNum = number[i]-'0';
        maxIdx = i;
    }
}
// 숫자 내림차순 정렬
for(int i=maxIdx; i<l; i++)
    v.push_back(make_pair(i, number[i]-'0'));
sort(v.begin(), v.end(), comp1);

// 숫자 인덱스 오름차순 정렬
for(int i=0; i<k-maxIdx; i++) {
    v.pop_back();
}
sort(v.begin(), v.end());  

for(int i=0; i<v.size(); i++) {
    cout << v[i].second << " ";
} cout << "\n";
*/