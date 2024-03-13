#include <iostream>
#include <string>

using namespace std;

int *parent;

void Union(int a, int b);
int Find(int a);
string Check(int a, int b);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    parent = new int[n+1];

    // 자기 인덱스값으로 초기화
    for(int i=0; i<=n; i++) parent[i] = i;

    while(m--) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if(cmd == 0) Union(a, b);
        else if (cmd == 1) cout << Check(a, b);
    }

    delete[] parent;
}

void Union(int a, int b) {
    // 대표 노드 저장
    a = Find(a);
    b = Find(b);

    // 다른 집합이면 합치기
    if(a != b) 
        parent[b] = a;
}

int Find(int a) {
    if(a == parent[a]) return a;
    else return parent[a] = Find(parent[a]);
}

string Check(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a==b) return "YES\n";
    else return "NO\n";
}