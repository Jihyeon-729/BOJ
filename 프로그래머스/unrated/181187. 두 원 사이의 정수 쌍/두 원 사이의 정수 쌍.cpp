#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long dr1, dr2;
    int upper, lower;
    long long answer = 0;
    
    // 왜 dr2*dr2하면 느리고, pow(dr2, 2)하면 빨라지지...?
    // 답도 틀렸다가 pow써서 맞았다... 왜...?
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