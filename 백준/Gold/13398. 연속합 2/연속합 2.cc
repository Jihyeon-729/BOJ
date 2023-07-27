// DP - gold5
// 23.07.27

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int N, result;
    vector<int> A, DL, DR;

    cin >> N;
    A.resize(N);
    DL.resize(N);
    DR.resize(N);

    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    DL[0] = A[0]; 
    result = A[0];
    for(int i=1; i<N; i++) {
        DL[i] = max(A[i], A[i]+DL[i-1]);
        result = max(result, DL[i]);
    }
    // cout << "result=" << result << "\n";

    DR[N-1] = A[N-1];
    for(int i=N-2; i>=0; i--) {
        DR[i] = max(A[i], A[i]+DR[i+1]);
    }

    // for(int i=0; i<N; i++) {
    //     cout << DL[i] << " ";
    // } cout << "\n";

    // for(int i=0; i<N; i++) {
    //     cout << DR[i] << " ";
    // } cout << "\n";

    for(int i=1; i<N-1; i++) {
        result = max(result, DL[i-1]+DR[i+1]);
    }

    cout << result << "\n";

    return 0;
}

/*
int main(void)
{
    int N, n, i, endi;
    vector<int> temp, v;

    cin >> N;
    for(i=0; i<N; i++) {
        cin >> n;
        temp.push_back(n);
    }

    i=0;
    while(i<N) {
        v.push_back(temp[i]);
        endi = v.size()-1;
        while(temp[i] * temp[i+1] >= 0 && i<N) {
            v[endi] += temp[i+1];
            i++;
        }
        i++;
    }

    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    } cout << "\n";

    return 0;
}
*/