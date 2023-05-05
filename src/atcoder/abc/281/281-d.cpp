/*
DFS
→ 100C50 はTLE

DP
→ dp[i][j][r]
  a1,,,aiまでの間でj個選んでいる時の、和をDで割ったあまりがrである時の総和の最大値
*/

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define _repe1(i,n) for(int i = 1; i <= (int)(n); ++i)
#define _repe2(i,s,n) for(int i = (int)(s); i <= (int)(n); ++i)
#define repe(...) _overload3(__VA_ARGS__, _repe2, _repe1)(__VA_ARGS__)
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using mii = map<int,int>;
using mll = map<ll,ll>;
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))
#define deg2rad(x) (x*M_PI/180.0)
#define rad2deg(x) (x*180.0/M_PI)
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
const int INF = 1.1e9;
const ll INFLL = 4.4e18;
const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

#ifdef LOCAL
#include "debug_print.hpp"
#define dbg(...) cerr << '(' << __LINE__ << ')' << endl; debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) (static_cast<void>(0))
#endif
// clang-format on

int main() {
    int n, k, d;
    in(n, k, d);
    vi a(n);
    rep(i, n) in(a[i]);

    const int CMAX = 101;
    // c++ の vector を使う方法だとちょっと長いので、今回はCの書き方で配列宣言する。
    // vector<vector<vector<ll>>> dp(CMAX, vector<vector<ll>>(CMAX, vector<ll>(CMAX, -1)));

    ll dp[CMAX][CMAX][CMAX];
    // 配列の初期化：下の2行は同じ結果
    // rep(i,CMAX) rep(j,CMAX) rep(r,CMAX) dp[i][j][r]=-1;
    memset(dp, -1, sizeof(dp));

    dp[0][0][0] = 0;

    rep(i, n) {
        rep(j, k + 1) {
            rep(r, d) {
                if (dp[i][j][r] == -1)
                    continue;

                // a_i を選ばない場合
                chmax(dp[i + 1][j][r], dp[i][j][r]);

                // a_i を選ぶ場合
                if (j < k) {
                    chmax(dp[i + 1][j + 1][(r + a[i]) % d], dp[i][j][r] + a[i]);
                }
            }
        }
    }

    out(dp[n][k][0]);
    return 0;
}
