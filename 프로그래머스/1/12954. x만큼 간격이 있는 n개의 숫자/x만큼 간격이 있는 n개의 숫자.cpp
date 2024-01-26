#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    long long llx = x;
    vector<long long> answer;
    for(int i=0; i<n; i++) {
        answer.push_back(llx);
        llx += (long long)x;
    }
    return answer;
}