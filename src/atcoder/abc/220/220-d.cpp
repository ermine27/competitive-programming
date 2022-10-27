#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i = (int)(n)-1; i => 0; --i)
#define fore(x,a) for(auto& (x):(a))
#define all(v) v.begin(), v.end()
#define npos string::npos
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const long long INFLL = 1e18;
const int mod = 998244353;

int main(){
    int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];

    vl dp(10);
    dp[a[0]] = 1;

    reps(i,1,n){
        vl dn(10);

        rep(j,10){
            int f = (j + a[i]) % 10;
            int g = (j * a[i]) % 10;

            dn[f] += dp[j];
            dn[g] += dp[j];

            dn[f] %= mod;
            dn[g] %= mod;
        }
        dp = dn;
    }

    rep(i,10) cout << dp[i] << endl;
}
