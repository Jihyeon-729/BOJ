#include <string>
#include <vector>
#include <iostream>

using namespace std;

int num(int n);

int solution(int n) {
    int answer = 0;
    int start = 1;
    int end = 1;
    int sum = 1;
    while(end<n) {
        while(sum<n) {
            end++;
            sum += end;
        } if(sum == n) answer++;
        
        while(sum >= n) {
            sum -= start;
            start++;
            if(sum==n) break;
        }
    }
    return answer+1;
}

int num(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    else return num(n/2) + num(n-n/2);
}