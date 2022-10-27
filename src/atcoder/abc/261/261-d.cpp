#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using mii = map<int,int>;
using mil = map<int,ll>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    int n, m;
    cin >> n >> m;
    vl x(n);
    mil bonus;
    rep(i,n) cin >> x[i];
    rep(i, m) {
        int ci, mi;
        cin >> ci >> mi;
        bonus[ci - 1] = mi;
    }

    vl dp(n + 1, -1);
    dp[0] = 0;

    rep(i,n){
        vl dpn(n + 1, -1);

        ll lmax = 0;
        rep(j,n+1){
            chmax(lmax, dp[j]);
        }
        dpn[0] = lmax;

        rep(j, n) {
            if (dp[j] == -1) continue;
            dpn[j + 1] = dp[j] + x[i] + bonus[j];
        }
        dp = dpn;
    }

    ll ans = 0;
    rep(i, n + 1) chmax(ans, dp[i]);

    cout << ans << endl;
    return 0;
}
