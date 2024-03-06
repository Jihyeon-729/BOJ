#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int ans = 0;
    int len = stones.size();
    
    int beg = *min_element(stones.begin(), stones.end());
    int end = *max_element(stones.begin(), stones.end());

    while(beg <= end) {
        
        int max_cnt=0, cnt=0;
        int mid = (beg+end) / 2;
        
        // 건너뛰는 최대 칸 수
        for(int i=0; i<len; i++) {
            if(stones[i] < mid) {
                cnt++;
            } else {
                // max_cnt를 else문 안에만 두면
                // mid보다 모든 stones[i]값이 작은 경우에는 제대로 확인 불가
                max_cnt = (cnt>=max_cnt? cnt : max_cnt);
                cnt = 0;
            }
        }
        // 따라서 반복문 끝나고 한번 더 확인
        max_cnt = (cnt>=max_cnt? cnt : max_cnt);
        
        // 칸수와 k값 체크
        if(max_cnt < k) {
            beg = mid+1;
            ans = (mid>ans? mid : ans);
        } else {
            end = mid-1;
        }
    }
    
    return ans;
}
