/*
区間DP

dp[l][r] = 区間(l,r)における最適な値
として、以下の漸化式を作る。

dp[l][r] = max {
              dp[l][r-1],
              dp[l+1][r],
              dp[l][r-1] + a[r],   (l+1 <= p[l] <= r   を満たす場合のみ)
              dp[l+1][r] + a[l]    (l   <= p[l] <= r-1 を満たす場合のみ)
           }

短い区間から１つずつ区間を伸ばしていき、
最終的に dp[0][N-1] が求める答えになる。

入力例1の場合のdpの値は以下のようになる。
左下の半分は使わない。対角線からはじめて1つ右隣り、2つ右隣り、、と順番に求めていき、最後に右上の[0][N-1]が求まる。

 0  0 40 60
 0  0 40 40
 0  0  0  0
 0  0  0  0

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
    int n;
    cin >> n;
    vi p(n), a(n);
    rep(i, n) {
        cin >> p[i] >> a[i];
        p[i]--;
    }
    vector<vi> dp(n, vi(n));

    rep(i, n - 1) {
        rep(j, n - i - 1) {
            int left = j;
            int right = i + j + 1;

            // 左側
            int leftval = dp[left + 1][right];
            if (left + 1 <= p[left] && p[left] <= right) {
                leftval += a[left];
            }
            // 右側
            int rightval = dp[left][right - 1];
            if (left <= p[right] && p[right] <= right - 1) {
                rightval += a[right];
            }

            dp[left][right] = max(leftval, rightval);
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}
