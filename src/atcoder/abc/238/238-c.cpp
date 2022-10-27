#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 998244353;

int main(){
    ll n, k = 1, ans = 0;
    cin >> n;
    ll ss;

    while(k <= n){
        k *= 10;

        ss = min(n + 1 - k / 10, k - k / 10);
        ss %= mod;
        ans += ss * (ss + 1) / 2;
        ans %= mod;
    }

    cout << ans;
}
