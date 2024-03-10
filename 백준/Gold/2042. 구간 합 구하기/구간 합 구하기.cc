#include <iostream>

using namespace std;

typedef long long ll;

ll *tree;
void update(ll b, ll c);
ll getSum(ll s, ll e);

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    ll treeSize = 1;
    while(treeSize<N) {
        treeSize *= 2;
    } treeSize *= 2;

    tree = new ll[treeSize+1];
    for(ll i = treeSize/2; i<treeSize/2+N; i++) {
        cin >> tree[i];
    }

    // build tree
    int i = treeSize-1;
    while (i!=1) {
        tree[i/2] += tree[i];
        i--;
    }

    // operate
    for(int i=0; i<M+K; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if(a==1) update(b + treeSize/2-1, c);
        else if (a==2) 
            cout << getSum(b + treeSize/2-1, c+treeSize/2-1) << "\n";
    }

    delete[](tree);

    return 0;
}

void update(ll b, ll c)
{
    ll diff = c - tree[b];
    while (b!=0) {
        tree[b] += diff;
        b /= 2;
    }
}

ll getSum(ll s, ll e)
{
    long pSum = 0;
    while(s<=e) {
        if(s%2==1) {
            pSum += tree[s];
            s++;
        }
        if(e%2==0) {
            pSum += tree[e];
            e--;
        }
        s /= 2;
        e /= 2;
    }
    return pSum;
}