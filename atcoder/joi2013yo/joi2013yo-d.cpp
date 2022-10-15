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
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

bool check(int t, int l, int h) {
    return l <= t && t <= h;
}

int main(){
    int d, n;
    cin >> d >> n;
    vi t(d), a(n), b(n), c(n);
    rep(i, d) cin >> t[i];
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    vvi dp(d, vi(n));

    rep(i, n) {
        if (check(t[0], a[i], b[i])) {
            dp[0][i] = 0;
        } else {
            dp[0][i] = -1;
        }
    }

    repf(i, d - 1) {
        rep(j, n) {
            if (check(t[i], a[j], b[j])) {
                rep(k, n) {
                    if (dp[i - 1][k] >= 0) {
                        chmax(dp[i][j], dp[i - 1][k] + abs(c[k] - c[j]));
                    }
                }
            }
        }
    }

    int ans = 0;
    rep(i,n){
        chmax(ans, dp[d-1][i]);
    }
    cout << ans << endl;
    return 0;
}
