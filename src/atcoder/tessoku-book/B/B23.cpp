/*
★５問題

巡回セールスマン問題
N<=8 くらいまで・・・順列全探索
N<=16 くらいまで・・・bit DP
N>16 ・・・近似値を求めるまでしかできない

bit DPについて
S = {A1,...,An} の中でどこまで通ったかの集合をビット列で持つ。

dp[S][v] = 頂点0からスタートして、{0,1,2,...,n-1}の部分集合を巡回する|S!|通りの経路のうち、
最短のものの距離。ただし、最後に頂点vに到達した時のみを考える。

dp[S∪v][v] = min u∈S (dp[S][u] + cost(u,v))

dp[{0,1,...,n-1}][0] が答え。

計算量はO(2^n * n^2)

参考：ビットDP(bit DP)の考え方 ~集合に対する動的計画法~
https://algo-logic.info/bit-dp/
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
    vector<double> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    // 各2点間の距離を求める
    vector<vector<double>> g(n, vector<double>(n));
    rep(i, n) {
        rep(j, n) {
            if (i == j)
                continue;
            double z = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            g[i][j] = z;
            g[j][i] = z;
        }
    }

    vector<vector<double>> dp(1 << n, vector<double>(n, 1e10));
    dp[0][0] = 0.0;

    rep(i, 1 << n) {
        rep(j, n) {
            rep(k, n) {
                if ((i & (1 << j)) == 0) {
                    chmin(dp[i | (1 << j)][j], dp[i][k] + g[j][k]);
                }
            }
        }
    }

    cout << setprecision(10) << dp[(1 << n) - 1][0] << endl;
    return 0;
}
