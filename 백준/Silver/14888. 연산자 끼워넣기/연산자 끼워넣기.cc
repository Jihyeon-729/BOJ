// DFS - silver1
// 23.07.23

#include <iostream>
#include <vector>

using namespace std;

int N, num;
int Max = -1000000001;
int Min = 1000000001;
int op[4] = {0, };  //add, sub, mul, div
vector<int> numseq;

void DFS(int depth, int result);

int main(void)
{
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> num;
        numseq.push_back(num);
    }
    cin >> op[0] >> op[1] >> op[2] >> op[3];

    DFS(0, numseq[0]);

    cout << Max << "\n" << Min << "\n";

    return 0;
}

void DFS(int depth, int result)
{
    if(depth == N-1) {
        // cout << "DFS(" << depth << "," << result <<")\n";
        if(Max < result)
            Max = result;
        if(Min > result)
            Min = result;
        return;
    }
    for(int i=0; i<4; i++) {
        if(op[i]>0) {
            op[i]--;
            if(i==0)        // +
                DFS(depth+1, result + numseq[depth+1]);
            else if(i==1)   // -
                DFS(depth+1, result - numseq[depth+1]);
            else if(i==2)   // *
                DFS(depth+1, result * numseq[depth+1]);
            else if(i==3)   // /
                DFS(depth+1, result / numseq[depth+1]);
            op[i]++;
        }
    }
}