/*
累積和で考える。

ex)
N=6, K=5
a: [    8 -3  5  7  0 -4 ]
s: [ 0  8  5 10 17 17 13 ]

l<r において、区間和がKとなるものを求めたい。
区間[l,r]の和は、Sr-Sl になる。

累積和を見ると、Sr-Sl=Kとなるものが条件に該当するものになる。
式を変形すると、Sr=K+Sl である。
rを固定して、条件に当てはまるlの数を数え上げる。

累積和を取っても、全ての区間[l,r]を調べるのに二重ループで行うと、 O(N/2) = O(N) の計算量が必要になりTLEになる。
そこでSi+Kの値を連想配列のキーにしてカウントするようにすると、計算量が足りる。
　
*/

#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vl = vector<long long>;


int main(){
    ll n,k;
    cin >> n >> k;
    vl a(n);
    rep(i, n) cin >> a[i];
    vl s(n+1);
    rep(i,n) s[i+1] = s[i] + a[i];

    unordered_map<ll,ll> mp;
    ll ans = 0;

    rep(i,n+1){
        ans += mp[s[i]];
        ++mp[s[i]+k];
    }

    cout << ans;
    return 0;    
}
