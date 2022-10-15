// WA:cbrtとsqrtの誤差バグが生じる

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;

    ll r1 = cbrt(n);
    for(int i = 1; i <= r1; ++i){
        ll r2 = sqrt(n/i);
        for(int j = i; j <= r2; ++j){
            ll r3 = n / i / j;
            ans += r3 - j + 1;
        }
    }

    cout << ans;
}
