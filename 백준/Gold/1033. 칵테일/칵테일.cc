// gcd - gold2
// 23.07.24

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int N;
long LCM = 1;
long mass[10];
bool visited[10];
vector<tuple<int, int, int>> tp[10];

long findGCD(long a, long b);
void DFS(int node);

int main(void)
{
    int a, b, p, q;
    long mgcd;

    cin >> N;
    for(int i=0; i<N-1; i++) {
        cin >> a >> b >> p >> q;
        tp[a].push_back(make_tuple(b, p, q));
        tp[b].push_back(make_tuple(a, q, p));
        LCM *= (p*q/findGCD(p, q));
    }

    mass[0] = LCM;
    DFS(0);
    mgcd = mass[0];

    for(int i=1; i<N; i++) {
        mgcd = findGCD(mgcd, mass[i]);
    }
    for(int i=0; i<N; i++) {
        cout << mass[i]/mgcd << " ";
    }
    cout << "\n";

    return 0;
}

long findGCD(long a, long b) {
    if(b==0)
        return a;
    else return findGCD(b, a%b);
}

void DFS(int node) {
    visited[node] = true;
    // cout << "curr = " << node << "\n";
    for(tuple<int, int, int> i : tp[node]) {
        int next = get<0>(i);
        // for(int i=0; i<N; i++) {
        //     cout << mass[i] << " ";
        // }
        // cout << "\n";
        if (!visited[next]) {
            mass[next] = mass[node] * get<2>(i) / get<1>(i);
            DFS(next);
        }
    }
}