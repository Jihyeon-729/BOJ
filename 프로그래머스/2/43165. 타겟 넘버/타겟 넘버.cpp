#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
vector<int> nums;

void operation(int cur, char op, int nxt, int target)
{
    if (nxt == nums.size()) {
        if(cur == target)
            answer++;
        return;
    }
    else {
        switch(op) {
            case '+':
                operation(cur+nums[nxt], '+', nxt+1, target);
                operation(cur+nums[nxt], '-', nxt+1, target);
                break;
            case '-':
                operation(cur-nums[nxt], '+', nxt+1, target);
                operation(cur-nums[nxt], '-', nxt+1, target);
                break;
        }
    }
}

int solution(vector<int> numbers, int target) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    nums = numbers;
    operation(0, '+', 0, target);
    operation(0, '-', 0, target);
    
    return answer/2;
}