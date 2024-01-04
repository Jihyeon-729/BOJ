#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string num = "";
    string answer = "";
    vector<int> nums;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') {
            nums.push_back(stoi(num));
            num = "";
        }
        else num += s[i];
    }
    if(num != "") nums.push_back(stoi(num));

    sort(nums.begin(), nums.end());
    answer += to_string(nums[0]) + ' ';
    answer += to_string(nums[nums.size() - 1]);
    return answer;
}