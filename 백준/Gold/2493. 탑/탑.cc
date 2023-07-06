// stack - gold5
// 23.07.06

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(void)
{
    int N, T, top;
    // int idx[100000001];
    vector<int> towers, receiver;
    vector<pair<int, int> > stack;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> T;
        towers.push_back(T);
    }

    top = 0;
    for (int i=0; i<N; i++) {
        T = towers[i];
        while (!stack.empty() && T > stack.back().second) {
            stack.pop_back();
        }
        if(!stack.empty() && T < stack.back().second) {
            top = stack.back().first;
        }
        if(stack.empty()) {
            top = 0;
        }
        stack.push_back(make_pair(i+1, T));
        receiver.push_back(top);
    }

    for(int i=0; i<N; i++) {
        cout << receiver[i] << " ";
    } cout << "\n";

    return 0;
}