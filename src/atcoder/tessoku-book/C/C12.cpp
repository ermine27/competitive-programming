/*
dp[i][j] jページまででi章まで決まっている段階での、最大の「小説の良さ」とする。

dp[i][j] = max(dp[i-1][k] + kページ～k-1ページまでを同じ章にした場合の小説の良さの増分）
　※ 1 <= k < j

3重ループになるが、N,M,Kが十分小さいので計算量は間に合う。
*/
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    vector<vector<int>> dp(k + 1, vi(n + 1, -999));
    dp[0][0] = 0;

    // 区間[l,r]までを同じ章にした場合の小説の良さの増分を計算する
    auto check = [&](int l, int r) -> int {
        int cnt = 0;
        rep(i, m) {
            if (l <= a[i] && b[i] <= r) {
                cnt++;
            }
        }
        return cnt;
    };

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 0; l < j; l++) {
                chmax(dp[i][j], dp[i - 1][l] + check(l + 1, j));
            }
        }
    }

    cout << dp[k][n] << endl;
    return 0;
}
