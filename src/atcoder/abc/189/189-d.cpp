#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;

int main(){
    int n;
    cin >> n;
    string s;
    vvl dp(n+1, vl(2));
    dp[0][0] = dp[0][1] = 1;
    rep(i,n){
        cin >> s;
        if(s == "AND"){
            dp[i+1][1] = dp[i][1];
            dp[i+1][0] = dp[i][1] + dp[i][0] * 2;
        } else{
            dp[i+1][1] = dp[i][1] * 2 + dp[i][0];
            dp[i+1][0] = dp[i][0];
        }
    }

    cout << dp[n][1] << endl;
    return 0;
}
