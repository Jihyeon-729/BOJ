#include <string>
#include <vector>
#include <algorithm>
// to use 'reverse', you need <algorithm> lib

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer, r, stack;
    
    r = numbers;
    reverse(r.begin(), r.end());
    
    answer.push_back(-1);
    stack.push_back(r[0]);
    for(int i=1; i<r.size(); i++) {
        while(!stack.empty() && r[i]>=stack.back())
            stack.pop_back();
        if(stack.empty())
            answer.push_back(-1);
        else
            answer.push_back(stack.back());
        stack.push_back(r[i]);
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}