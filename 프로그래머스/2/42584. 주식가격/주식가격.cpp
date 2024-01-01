#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// 가격이 떨어지지 않은 기간보다는,
// 최초로 가격이 떨어질 때까지 걸린 시간이 더 적절한 표현
vector<int> solution(vector<int> prices) {
    stack<int> st;
    vector<int> answer(prices.size());
    
    for(int i=0; i<prices.size(); i++) {
        while(!st.empty() && prices[i] < prices[st.top()]) {
            answer[st.top()] = i-st.top();
            st.pop();
        }
        st.push(i);
    }
    
    while(!st.empty()) {
        answer[st.top()] = prices.size() - 1 - st.top();
        st.pop();
    }
    return answer;
}