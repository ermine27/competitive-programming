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
    int n, m;
    cin >> n >> m;
    vi d(n), c(m);
    rep(i, n) cin >> d[i];
    rep(i, m) cin >> c[i];

    vvi dp(n + 1, vi(m + 1, 1e9));
    rep(j, m + 1) dp[0][j] = 0;

    repf(i, n) {
        repf(j, m) {
            if (j < i) continue;
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + d[i - 1] * c[j - 1]);
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}
