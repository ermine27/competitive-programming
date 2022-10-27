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
    vl c(n);
    rep(i, n) cin >> c[i];

    sort(all(c));

    const int d = 1000000007;
    ll ans = 1;
    rep(i,n){
        ans *= c[i] - i;

        if(ans > d) ans %= d;
    }

    cout << ans;
}
