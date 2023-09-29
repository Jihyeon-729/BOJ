#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long dr1, dr2;
    int upper, lower;
    long long answer = 0;
    
    dr1=(long)r1; dr2=(long)r2;
    for(int i=1; i<=r1; i++) {
        upper = floor(sqrt(pow(dr2, 2)-pow(i, 2)));
        lower = ceil(sqrt(pow(dr1, 2)-pow(i, 2)));
        answer += (upper-lower+1);
    }
    for(int i=r1+1; i<=r2; i++) {
        upper = floor(sqrt(pow(dr2, 2)-pow(i, 2)));
        answer += (upper+1);
    }
    answer *= 4;

    return answer;
}