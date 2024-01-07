/*
ミニマックス（Mini-Max）法

太郎と次郎の動きはミニマックス法と同じ動きをしているのでDPを使えばO(N^2)の計算量で求められる。
A21の問題と同様にボトムアップで求めていく。
この問題ではコードをシンプルにするためにDPの二次元配列のうち右下半分は使わず、
左上に求める答えが入るようにしている。
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
    vector<vi> dp(n, vi(n));
    rep(i, n) cin >> dp[n - 1][i];

    for (int i = n - 1; i > 0; i--) {
        rep(j, i) {
            if (i % 2 == 1)
                dp[i - 1][j] = max(dp[i][j], dp[i][j + 1]);
            else
                dp[i - 1][j] = min(dp[i][j], dp[i][j + 1]);
        }
    }

    cout << dp[0][0] << endl;
    return 0;
}
