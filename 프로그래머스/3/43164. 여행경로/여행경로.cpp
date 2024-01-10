#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt = 0;
bool checked[10000];
vector<string> answer;
vector<vector<string>> ticks;

bool change (vector<string> a, vector<string> b);
void DFS(string from, int depth, vector<string> &plan);

vector<string> solution(vector<vector<string>> tickets) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    vector<string> plan;
    
    plan.push_back("ICN");
    ticks = tickets;
    cnt = tickets.size();
    DFS("ICN", 1, plan);
    
    return answer;
}

void DFS(string from, int depth, vector<string> &plan)
{
    if(depth == cnt+1) {
        if (answer.empty())
            answer = plan;
        else if(change(answer, plan))
            answer = plan;
        return;
    }
    for(int i=0; i<cnt; i++) {
        if (!checked[i] && ticks[i][0]==from) {
            checked[i] = true;
            plan.push_back(ticks[i][1]);
            DFS(ticks[i][1], depth+1, plan);
            plan.pop_back();
            checked[i] = false;
        }
    }
}

bool change (vector<string> a, vector<string> b)
{
    for(int i=0; i<cnt; i++) {
        for(int j=0; j<3; j++) {
            if(a[i][j] != b[i][j])
                return a[i][j] > b[i][j];
        }
    } 
}