// number theory - gold5
// 23.07.22

#include <iostream>
#include <cmath>

#define MAX 10000001
using namespace std;
typedef long long int lli;
bool isPrime[MAX];

int main(void)
{
	ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    lli A, B, rB;
    int cnt = 0;

    for(lli i=0; i<MAX; i++) {
        isPrime[i] = true;
    }

    isPrime[1] = false;
    for(lli i=2; i<MAX; i++) {
        if(isPrime[i]==true) {
            for(lli j=2; j<MAX && i*j<MAX; j++) {
                isPrime[i*j] = false;
                //if(i*j < MAX) break;
            }
        }
    }

    cin >> A >> B;
    rB = sqrt((double)B);
    //rB = sqrt(B);
/*
    // cout << "rB = " << rB << "\n";
    for(lli i=2; i<=rB; i++) {
        if(isPrime[i]) {
            // cout << i << " -> ";
            lli power = i*i;
            while(power<=B) {
                if(A<=power) {
                    // cout << power << ", ";
                    cnt++; 
                }
                power*=i;
            } cout << "\n";
        }
    }
*/
    for(lli i=2; i<=rB; i++) {
        if(isPrime[i]) {
            double power = i*i;    // 이거 lli에서 double로 고치니까 됨.. out of range 문제인듯?
            while(power<=B) {
                if(A<=power) cnt++; 
                power*=i;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}