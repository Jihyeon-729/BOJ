// number theory - gold1
// 23.07.23

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int cnt = 0;
    long Min, Max;
    cin >> Min >> Max;
    vector<bool> Check(Max-Min+1);

    for(long i=2; i*i<=Max; i++) {
        long Pow = i*i;
        long start_idx = Min/Pow;
        
        if (Min%Pow != 0) {
            start_idx+=1;
        }

        for(long j=start_idx; Pow*j<=Max; j++) {
            Check[(int)((j*Pow)-Min)] = true;
            // cout << "j,Pow=" << j << "," << Pow << "\n";
            // cout << "j*Pow=" << j*Pow << "\n";
        }
    }

    for(long i=0; i<=Max-Min; i++) {
        // cout << "i=" << i << "->";
        if(!Check[i]) {
            cnt++;
            // cout << i;
        }
        // cout << " / ";
    }
    // cout << "\n";

    cout << cnt << "\n";

    return 0;
}

/*
int main(void)
{
    long Min, Max, power, tmp;
    double rMin, rMax;  //root min, max
    int answer = 0;
    vector<long> Pow;

    cin >> Min >> Max;
    rMin = sqrt(Min);
    rMax = sqrt(Max);

    if (rMin != (double)((long)rMin))
        rMin += 1;
    
    for(long i=2; i<=rMax; i++) {
        power = i*i;
        Pow.push_back(power);
    }

    tmp = (long)Min;
    while(tmp <= Max) {
        for(long num = rMin; num <= rMax; num++) {
            cout << "tmp,num = " << tmp << "," << num << "\n";
            if(Pow[num]) continue;
            else if (tmp%num == 0) {
                answer += 1;
                cout << "(" << tmp << "," << num << ") ";
            }
        }
        tmp += 1;
    } cout << "\n";

    cout << answer << "\n";

    return 0;
}
*/