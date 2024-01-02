#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

/*
새로 배운 것
<algorithm> next_permutation(s.begin(), s.end()) -> 오름차순 정렬 후 사용해야 함. 현재 주어진 순열 기준으로, 사전 순의 다음 순열로 바꾼다. 내림차순으로 정렬되어있을 경우 prev_permutation하면 됨
<cstdlib> atoi
<set> iterator 사용한 접근법
<string> substr
에라토스테네스의 체
for문은 index 초기화 -> 반복조건 확인 -> 조건문 내부 수행 -> 인덱스 갱신
*/

using namespace std;

bool isPrime(int num) 
{
    if(num<2) return false;
    for(int i=2; i<=sqrt(num); i++) {
        if(num%i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    // 선언
    set<int> s;
    set<int>::iterator it;
    int answer = 0;
    string tmpstr;
    
    // 숫자 순열셋 생성
    sort(numbers.begin(), numbers.end());
    do {
        for(int i=1; i<=numbers.size(); i++) {
            tmpstr = numbers.substr(0, i);
            s.insert(stoi(tmpstr));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    for(it = s.begin(); it!=s.end(); it++) {
        //cout << *it << " ";
        if(isPrime(*it)) answer++;
    }
    
    return answer;
}
