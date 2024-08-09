#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, m, h;
bool ladder[31][31];

void min_found(int lmt, int cnt);
bool all_match(void);

int main(void) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> h;

    int r, c;
    for (int i = 0; i < m; i++)
    {
        cin >> r >> c;
        ladder[r][c] = true;
    }

    int minh, ans;
    for(minh = 0; minh<4; minh++) {
        min_found(minh, 0);
    }
    cout << "-1\n";

    return 0;
}

void min_found(int lmt, int cnt) {
    
    if(lmt == cnt) {
        if(all_match()) {
            cout << cnt << "\n";
            exit(0);
        }
        return;
    }

    /*
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=n; j++) {
            if(ladder[i][j-1] || ladder[i][j] || ladder[i][j+1])
                continue;
            ladder[i][j] = true;
            min_found(lmt, cnt+1);
            ladder[i][j] = false;

            while(!ladder[i][j-1] && !ladder[i][j+1])
                j++;
        }
    }
    */

    for(int j=1; j<=n; j++) {
        for(int i=1; i<=h; i++) {
            if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1])
                continue;
            ladder[i][j] = true;
            min_found(lmt, cnt + 1);
            ladder[i][j] = false;

            while (!ladder[i][j - 1] && !ladder[i][j + 1])
                i++;
        }
    }

    return;
}

bool all_match(void) {
    for(int j=1; j<=n; j++) {
        int curcol = j;
        for(int i=1; i<=h; i++) {
            if(ladder[i][curcol]) curcol++;
            else if (ladder[i][curcol-1]) curcol--;
        }
        if(curcol != j) return false;
    } return true;
}

/*
#define pii pair<int, int>

int n, m, h;
bool found;
pii p;
set<pii> spii;

void dfs(int nth, set<pii> piiset, int row);
void test(void);

int main(void)
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        cin >> p.first >> p.second;
        spii.insert(p);
    }

    dfs(0, spii, 1);

    return 0;
}

void dfs(int nth, set<pii> piiset, int row)
{
    test();
    if (found) {
        cout << nth << "\n"; return;
    } else if (nth == 6) {
        cout << "-1\n"; return;
    }

    for (int i = row; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            p = {i, j};
            if (spii.find(p) != spii.end()) {
                if (spii.find({i - 1, j}) != spii.end()) {
                    piiset.insert(p);
                    dfs(nth+1, piiset, i);
                    iterator<set<pii>>::it;
                    it = piiset.find(p);
                    piiset.erase(it);
                }
            }
        }
    }
}

void test(void)
{
    iterator<set<pii>>::it;


}
*/