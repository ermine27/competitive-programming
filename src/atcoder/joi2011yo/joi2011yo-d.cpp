#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;

int main(){
    int n;
    cin >> n;
    vi x(n);
    rep(i, n) cin >> x[i];

    vvl dp(n-1, vl(21));
    dp[0][x[0]] = 1;

    rep(i,n-2){
        rep(j,21){
            int xi = x[i+1];

            if(j-xi>=0){
                dp[i+1][j-xi] += dp[i][j];
            }
            if(j+xi<=20){
                dp[i+1][j+xi] += dp[i][j];
            }
        }
    }

    cout << dp[n-2][x[n-1]] << endl;
    return 0;
}
