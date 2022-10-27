#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;


int main(){
    int n;
    ll k,x,ksum = 0;
    cin >> n >> k >> x;
    vi m(n);
    int ai, di;

    ll ans = 0;
    rep(i, n){
        cin >> ai;
        di = ai / x;
        ksum += di;
        m[i] = ai % x;
    }

    ans += max(0LL, ksum-k) * x;

    k = max(0LL, k-ksum);

    sort(all(m));
    rep(i,n-k)  ans += m[i];

    cout << ans;
}
