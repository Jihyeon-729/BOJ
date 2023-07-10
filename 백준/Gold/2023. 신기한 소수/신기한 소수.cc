// dfs - gold5
// 23.07.10

#include <iostream>
#include <cmath>

using namespace std;

int N;

bool checkPrime(int num);
void checkCoolPrime(int num, int ndig, int depth);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i=2; i<10; i++) {
        checkCoolPrime(0, i, 1);
    }

    return 0;
}

bool isPrime(int num) {
    for(int i=2; i<=sqrt(num); i++) {
        if(num%i == 0) return false;
    }
    return true;
}

void checkCoolPrime(int num, int ndig, int depth) {
    num = num*10 + ndig;
    if(isPrime(num)) {
        if(depth < N) {
            for(int i=0; i<10; i++)
                checkCoolPrime(num, i, depth+1);
        }
        else if (depth == N)
            cout << num << "\n";
    }
    return;
}