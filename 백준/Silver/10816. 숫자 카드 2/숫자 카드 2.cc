#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    
    map<int, int> card;
 
    int n;
    for(int i=0; i<N; i++) {
        cin >> n;
        if (card.find(n) == card.end()) {
            card[n] = 1;
        } else card[n]++;
    }
    
    int K;
    cin >> K;
    for(int i=0; i<K; i++) {
        cin >> n;
        if (card.find(n) == card.end()) {
            cout << "0 ";
        } else cout << card[n] << " ";
    }
    cout << "\n";
    
    return 0;
}