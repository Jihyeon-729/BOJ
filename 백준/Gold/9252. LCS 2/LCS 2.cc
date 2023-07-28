#include <iostream>
#include <vector>
#include <string>

using namespace std;

string a, b;
int D[1001][1001];
vector<char> answer;

void DFS(int y, int x);

int main(void)
{
    // DP
    cin >> a >> b;
    for(int i=1; i<=a.size(); i++) {
        for(int j=1; j<=b.size(); j++) {
            if(a[i-1] == b[j-1]) D[i][j] = D[i-1][j-1]+1;
            else D[i][j] = max(D[i-1][j], D[i][j-1]);
            // cout << D[i][j] << " ";
        }
        // cout << "\n";
    }

    // search
    DFS(a.size(), b.size());

    // print
    cout << D[a.size()][b.size()] << "\n";
    for(int i=answer.size()-1; i>=0; i--) {
        cout << answer[i];
    } cout << "\n";

    return 0;
}

void DFS(int y, int x) 
{
    if(y==0 || x==0) return;
    else {
        if(a[y-1] == b[x-1]) {
            answer.push_back(a[y-1]);
            DFS(y-1, x-1);
        }
        else {
            if(D[y-1][x] > D[y][x-1])
                DFS(y-1, x);
            else DFS(y, x-1);
        }
    }
}

/*
int main(void)
{
    int i, j;
    string a, b;
    vector<char> answer;
    vector<vector<int>> D;

    cin >> a >> b;
    // cout << a.size() << " " << b.size() << "\n";

    for(i=0; i<a.size(); i++) {
        vector<int> tmp(b.size());
        D.push_back(tmp);
    }

    if(b[0] == a[0]) D[0][0] = 1;
    else D[0][0] = 0;
    for(j=1; j<b.size(); j++) {
        if (b[j] == a[0]) D[0][j] = 1;
        else D[0][j] = D[0][j-1];
    }
    for(i=1; i<a.size(); i++) {
        if(a[i] == b[0]) D[i][0] = 1;
        else D[i][0] = D[i-1][0];
    }

    for(i=1; i<a.size(); i++) {
        for(j=1; j<b.size(); j++) {
            if(a[i] == b[j]) D[i][j] = D[i-1][j-1]+1;
            else D[i][j] = max(D[i-1][j], D[i][j-1]);
            cout << D[i][j] << " ";
        }
        cout << "\n";
    }

    i = a.size()-1; j = b.size()-1;
    while(D[i][j]>0) {
        cout << "(i, j) = (" << i << ", " << j << ")\n";
        if(a[i] == b[j]) {
            answer.push_back(a[i]);
            i--; j--;
        }
        else {
            if(i>0 && (D[i-1][j] == D[i][j]))
                i--;
            else if (j>0 && (D[i][j-1] == D[i][j]))
                j--;
        }
    }

    for(i=answer.size()-1; i>=0; i--) {
        cout << answer[i];
    } cout << "\n";

    return 0;
}
*/