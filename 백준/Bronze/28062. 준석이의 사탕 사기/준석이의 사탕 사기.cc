#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    int sum=0, min=1001;
    vector<int> a(1000);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> a[i];
        if(a[i]<min && a[i]%2==1) {
            min = a[i];
        }
        sum += a[i];
    }
    if(sum%2 == 0)
        cout << sum << "\n";
    else cout << sum-min << "\n";

    return 0;
}