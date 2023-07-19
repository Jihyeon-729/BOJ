#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int N, n, idx, nidx, pidx;
    int sum, prd, tsum;
    vector<int> nNum, pNum;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> n;
        if (n<=0) nNum.push_back(n);
        else pNum.push_back(n);
    }
    sort(nNum.begin(), nNum.end());
    sort(pNum.rbegin(), pNum.rend());

    // for(int i=0; i<nNum.size(); i++)
    //     cout << nNum[i] << " ";
    // cout << "\n";
    // for(int i=0; i<pNum.size(); i++)
    //     cout << pNum[i] << " ";
    // cout << "\n";

    idx = 0;
    tsum = 0;
    while(idx+1 < nNum.size()) {
        sum = nNum[idx] + nNum[idx+1];
        prd = nNum[idx] * nNum[idx+1];
        tsum += (sum < prd)? prd : sum;
        idx += 2;
    }
    if (idx == nNum.size()-1) {
        tsum += nNum[idx];
    }
    idx = 0;
    while(idx+1 < pNum.size()) {
        sum = pNum[idx] + pNum[idx+1];
        prd = pNum[idx] * pNum[idx+1];
        tsum += (sum < prd)? prd : sum;
        idx += 2;
    }
    if (idx == pNum.size()-1) {
        tsum += pNum[idx];
    }

    cout << tsum << "\n";

    return 0;
}