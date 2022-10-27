// 最長共通部分列
#include <bits/stdc++.h>
using namespace std;

#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define repf(i, n) reps(i, 1, n + 1)
using vi = vector<int>;
using vvi = vector<vi>;

int lcs(string x, string y) {
    int xlen = x.length();
    int ylen = y.length();
    x = ' ' + x;
    y = ' ' + y;

    vvi dp(xlen + 1, vi(ylen + 1));

    repf(i, xlen) {
        repf(j, ylen) {
            if (x[i] == y[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[xlen][ylen];
}

int main() {
    int q;
    cin >> q;
    string x, y;
    rep(i, q) {
        cin >> x >> y;
        cout << lcs(x, y) << endl;
    }

    return 0;
}
