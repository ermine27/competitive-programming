#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, min=10000000, max=-10000000;
    long long sum=0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a;
        if(a < min) min = a;
        if(a > max) max = a;
        sum += a;
    }
    cout << min << ' ' << max << ' ' << sum << endl;
}
