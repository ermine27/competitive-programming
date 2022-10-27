// 連鎖行列積
#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)
#define repf(i,n) reps(i,1,n+1)
using vi = vector<int>;
using vvi = vector<vi>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int n;
    cin >> n;

    vi p(n + 1);
    rep(i, n) { cin >> p[i] >> p[i + 1]; }

    vvi dp(n + 1, vi(n + 1));

    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            int tmp = INT_MAX;

            for (int k = i; k <= j - 1; ++k) {
                chmin(tmp, dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
            dp[i][j] = tmp;
        }
    }

    cout << dp[1][n] << endl;
    return 0;
}
