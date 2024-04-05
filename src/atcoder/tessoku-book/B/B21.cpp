/*
★６問題

区間DPの応用問題

dp[l][r] = Sの区間(l,r)における、作ることができる回文の最大文字数

初期値は以下の2通り。
  dp[i][i] = 1
  dp[i][i+1] = 2　（2つ選ぶ。隣り合う2文字が同じ場合のみ）

状態遷移は以下の3通り。
1.左端を1文字延ばす　dp[l][r] = dp[l+1][r]
2.右端を1文字延ばす　dp[l][r] = dp[l][r-1]
3.左右の端を1文字延ばし、回文に追加する dp[l][r] = dp[l+1][r-1] + 2

dp[l][r] = max {
              dp[l+1][r],
              dp[l][r-1],
              dp[l+1][r-1] + 2,   (S[l] = S[r]  を満たす場合のみ)
           }

短い区間から１つずつ区間を伸ばしていき、
最終的に dp[0][N-1] が求める答えになる。


入力例1の場合のdpの値は以下のようになる。
左下の半分は使わない。対角線からはじめて1つ右隣り、2つ右隣り、、と順番に求めていき、最後に右上の[0][N-1]が求まる。

dp: [ 1 1 1 1 3 3 3 3 3 3 4 ]
    [ 0 1 1 1 3 3 3 3 3 3 4 ]
    [ 0 0 1 1 1 1 1 2 2 2 4 ]
    [ 0 0 0 1 1 1 1 2 2 2 4 ]
    [ 0 0 0 0 1 1 1 2 2 2 2 ]
    [ 0 0 0 0 0 1 1 2 2 2 2 ]
    [ 0 0 0 0 0 0 1 2 2 2 2 ]
    [ 0 0 0 0 0 0 0 1 1 1 1 ]
    [ 0 0 0 0 0 0 0 0 1 1 1 ]
    [ 0 0 0 0 0 0 0 0 0 1 1 ]
    [ 0 0 0 0 0 0 0 0 0 0 1 ]

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
    string s;
    cin >> n >> s;
    vector<vi> dp(n, vi(n));

    rep(i, n) { dp[i][i] = 1; }
    rep(i, n - 1) {
        if (s[i] == s[i + 1])
            dp[i][i + 1] = 2;
        else
            dp[i][i + 1] = 1;
    }

    for (int len = 2; len < n; len++) {
        rep(left, n - len) {
            int right = left + len;

            dp[left][right] = max(dp[left + 1][right], dp[left][right - 1]);
            if (s[left] == s[right]) {
                dp[left][right] = max(dp[left][right], dp[left + 1][right - 1] + 2);
            }
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}
