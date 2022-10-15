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


int main(){
    const string c = "chokudai";
    const int clen = c.length();
    const int mod = 1000000007;
    string s;
    cin >> s;
    int slen = s.length();

    vvl dp(clen+1, vl(slen+1));
    rep(i,slen+1) dp[0][i] = 1;

    rep(i, clen){
        rep(j, slen){
            if(s[j] == c[i])
                dp[i+1][j+1] = (dp[i+1][j] + dp[i][j]) % mod;
            else
                dp[i+1][j+1] = dp[i+1][j];
        }
    }

    cout << dp[clen][slen];
}
