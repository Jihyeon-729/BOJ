// sort - silver1
// 23.07.09

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T, N;
    int score1, score2, temp, answer;
    vector<pair<int, int> > v;

    cin >> T;
    for(int i=0; i<T; i++) {
        v.clear();

        cin >> N;
        for(int j=0; j<N; j++) {
            cin >> score1 >> score2;
            v.push_back(make_pair(score1, score2));
        }
        sort(v.begin(), v.end());

        temp = 0;
        answer = 1;
        for(int j=1; j<N; j++) {
            if (v[temp].second>v[j].second) {
                  answer++;
                  temp = j;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}