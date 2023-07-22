// number theory - gold5
// 23.07.22

#include <iostream>
#include <unistd.h>
#include <string>
#include <cmath>

#define MAX 10000001
using namespace std;
typedef long long int lli;
bool isPrime[MAX];

int main(void)
{
	ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    int N, L, R, n, answer; // PrimePalindrome
    bool found = false;
    string numstr;
    char const *c_numstr;

    for(lli i=0; i<MAX; i++) {
        isPrime[i] = true;
    }

    isPrime[1] = false;
    for(int i=2; i<=sqrt(MAX); i++) {
        if(isPrime[i]==true) {
            for(int j=i+i; j<MAX; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    cin >> N;
    n = N;
    for(int n=N; n<MAX && !found; n++) {
        if (isPrime[n]) {
            numstr = to_string(n);
            // c_numstr = numstr.c_str();
            // cout << numstr << "\n";
            L = 0; R = numstr.size()-1;
            // cout << "L, R = " << L << ", " << R << "\n";
            while (true) {
                if (L>=R) {
                    found = true; 
                    answer = n;
                    break;
                }
                else if(numstr[L] == numstr[R]) {
                    // cout << c_numstr[L] << " " << c_numstr[R] << " / ";
                    L++; R--;
                }
                else break;
            } //cout << "\n";
        }
    }

    cout << answer << "\n";

    return 0;
}