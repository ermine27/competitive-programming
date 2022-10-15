#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define repf(i, n) reps(i, 1, n + 1)
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n, m;
    cin >> n >> m;
    vi c(m + 1);
    repf(i, n) cin >> c[i];

    vvi dp(m + 1, vi(n + 1));
    repf(i, n) dp[0][i] = INT_MAX;
    dp[0][0] = 0;

    repf(i, m) {
        repf(j, n) {
            if (j >= c[i]) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - c[i]] + 1);

            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[m][n] << endl;
    return 0;
}
