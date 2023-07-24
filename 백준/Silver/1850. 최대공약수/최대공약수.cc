// gcd - silver1
// 23.07.24

#include <iostream>

using namespace std;

long GCD(long a, long b);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long a, b, result;
    cin >> a >> b;

    result = GCD(a, b);

    for(int i=0; i<result; i++)
        cout << 1;
    cout << "\n";

    return 0;
}

long GCD(long a, long b)
{
    if (b==0)
        return a;
    else
        return GCD(b, a%b);
}