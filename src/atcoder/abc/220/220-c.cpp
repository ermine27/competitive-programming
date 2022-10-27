#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    ll x;
    cin >> x;

    ll asum = 0;
    rep(i,n) asum += a[i];

    ll div = x / asum;
    ll mod = x % asum;
    ll ans = n * div;

    int i = 0;
    while(mod >= 0){
        mod -= a[i];
        ++i;
    }

    cout << ans + i;

}