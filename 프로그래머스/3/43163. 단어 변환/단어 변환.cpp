#include <string>
#include <vector>

using namespace std;

int ans = 51;
int wordscnt;
bool visited[50];
string targ;
vector<string> wordsvec;

int diff(string a, string b);
void DFS(string curstr, int depth);

int solution(string begin, string target, vector<string> words) {    
    targ = target;
    wordscnt = words.size();
    wordsvec = words;
    
    for(int i=0; i<wordscnt; i++) {
        if(diff(begin, words[i]) == 1) {
            visited[i] = true;
            DFS(words[i], 1);
            visited[i] = false;
        }
    }
    if(ans == 51) ans = 0;
    return ans;
}

void DFS(string curstr, int depth)
{
    if(curstr == targ) {
        if(ans > depth)
            ans = depth;
    }
    for(int i=0; i<wordscnt; i++) {
        if(curstr == wordsvec[i]) continue;
        if(!visited[i] && diff(curstr, wordsvec[i])==1) {
            visited[i] = true;
            DFS(wordsvec[i], depth+1);
            visited[i] = false;
        }
    }
}

int diff(string a, string b) {
    int diff = 0;
    for(int i=0; i<a.size(); i++) {
        if(a[i]!=b[i]) diff++;
    }
    return diff;
}