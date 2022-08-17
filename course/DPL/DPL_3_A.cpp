/*
最大正方形 : Largest Square
*/
#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f

#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define _repe1(i,n) for(int i = 1; i <= (int)(n); ++i)
#define _repe2(i,s,n) for(int i = (int)(s); i <= (int)(n); ++i)
#define repe(...) _overload3(__VA_ARGS__, _repe2, _repe1)(__VA_ARGS__)
#define per(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define perf(i,n) for(int i = (int)(n); i >= 1; --i)
#define _fore1(x,a) for(const auto& x:a)
#define _fore2(k,v,a) for(const auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)

#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())

template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename T> T square (T x) { return x * x; }

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))

template<typename... T> void in(T& ... a){ (cin >> ... >> a); }
template<typename T> void vecin(T &x, int n){ rep(i,n) cin >> x[i]; }
template<typename T> void vecin(T &x){ vecin(x, sz(x)); }

int main(){
    int h, w;
    in(h, w);
    vvis(c, h, w);
    rep(i, h) vecin(c[i]);

    int ans = 0;
    vvis(dp, h, w);
    rep(i, h) {
        if (!c[i][0]) {
            dp[i][0] = 1;
            ans = 1;
        }
    }
    rep(i, w) {
        if (!c[0][i]) {
            dp[0][i] = 1;
            ans = 1;
        }
    }

    rep(i, 1, h) {
        rep(j, 1, w) {
            if (c[i][j] == 0) {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                chmax(ans, dp[i][j]);
            }
        }
    }

    cout << square(ans) << endl;
    return 0;
}
