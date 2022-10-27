#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;


int main(){
    int n;
    cin >> n;

    map<ll,ll> a;
    int ai;
    rep(i,n){
        cin >> ai;
        a[ai % 200]++;
    }

    ll ans = 0;
    fore(x,a){
        ans += max(0LL, x.second * (x.second - 1) / 2);
    }
    cout << ans;
}