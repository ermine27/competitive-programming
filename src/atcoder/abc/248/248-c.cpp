#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vl = vector<long long>;

const int mod998244353 = 998244353;

int main(){
    int n,m,k;
    cin >> n >> m >> k;

    vl dp(k+1);
    dp[0] = 1;
    rep(i,n){
        vl dp2(k+1);
        rep(j,k){
            rep(p,m){
                if(j+p+1 < k+1){
                    dp2[j+p+1] = (dp2[j+p+1] + dp[j]) % mod998244353 ;
                }
            }
        }
        dp = dp2;
    }

    ll ans = 0LL;
    rep(i,k+1){
        ans += dp[i];
        ans %= mod998244353;
    }

    cout << ans;
    return 0;
}
