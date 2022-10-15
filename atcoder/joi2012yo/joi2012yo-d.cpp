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
using mii = map<int,int>;

const int MOD = 10000;

int main(){
    int n, k;
    cin >> n >> k;
    mii fixed;
    rep(i, k) {
        int ai, bi;
        cin >> ai >> bi;
        fixed[ai] = bi;
    }

    // 3次元配列1つでもいいが、2次元配列を2つ用いる
    // dp1:1日連続、dp2:2日連続
    vvi dp1(n + 1, vi(4)), dp2(n + 1, vi(4));

    if (fixed[1]) {
        dp1[1][fixed[1]] = 1;
    } else {
        repf(i, 3) dp1[1][i] = 1;
    }

    for(int i=2; i<=n; ++i){
        int f = fixed[i];

        if (f) {
            dp2[i][f] = dp1[i - 1][f];
            repf(j, 3) {
                if (j != f) {
                    dp1[i][f] += dp1[i - 1][j];
                    dp1[i][f] += dp2[i - 1][j];
                    dp1[i][f] %= MOD;
                }
            }
        } else {
            repf(j, 3) {
                dp2[i][j] = dp1[i - 1][j];

                repf(k, 3) {
                    if (j != k) {
                        dp1[i][j] += dp1[i - 1][k];
                        dp1[i][j] += dp2[i - 1][k];
                        dp1[i][j] %= MOD;
                    }
                }
            }
        }
    }

    ll ans = 0;
    repf(i,3){
        ans += dp1[n][i] + dp2[n][i];
    }
    cout << ans % MOD << endl;
    return 0;
}
