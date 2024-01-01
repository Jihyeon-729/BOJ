#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

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