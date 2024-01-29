#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int a = 10;
    int b = 1;
    while(n>0) {
        answer += (n%a)/b;
        n /= 10;
    }
    return answer;
}