#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main(){
    ll n;
    cin >> n;
    ll ans = 0;

    for(ll i = 1; i*i*i <= n; ++i){
        for(ll j = i; i*j*j <= n; ++j){
            ll r3 = n / (i * j);
            ans += r3 - j + 1;
        }
    }

    cout << ans;
}
