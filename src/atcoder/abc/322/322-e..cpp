#ifdef INCLUDE_MAIN

// n進数に置き換える方法
#if 1
vi int2vec(int x, int k, int p) {
    p++;
    vi ret(k);
    rep(i, k) {
        ret[i] += x % p;
        x /= p;
    }
    return ret;
}
int vec2int(vi x, int k, int p) {
    p++;
    int ret = 0, c = 1;
    rep(i, k) {
        ret += c * x[i];
        c *= p;
    }
    return ret;
}

int main() {
    int n, k, p;
    in(n, k, p);
    vl c(n);
    vvi a(n, vi(k));
    rep(i, n) {
        in(c[i]);
        rep(j, k) in(a[i][j]);
    }

    const ll DONOT = INFLL;
    int pmax = 1;
    rep(i, k) pmax *= p + 1;
    vvl dp(n + 1, vl(pmax, DONOT));
    dp[0][0] = 0;

    rep(i, n) {
        rep(j, pmax) {
            if (dp[i][j] != DONOT) {
                chmin(dp[i + 1][j], dp[i][j]);
                vi nxtvec = int2vec(j, k, p);
                rep(t, k) { nxtvec[t] = min(nxtvec[t] + a[i][t], p); }
                int nxtint = vec2int(nxtvec, k, p);
                chmin(dp[i + 1][nxtint], dp[i][j] + c[i]);
            }
        }
    }

    ll ans = dp[n][pmax - 1];
    if (ans == INFLL)
        ans = -1;
    out(ans);
    return 0;
}
#endif

// キーをmapで扱う方法
#if 1
int main() {
    int n, k, p;
    in(n, k, p);
    vl c(n);
    vvi a(n, vi(k));
    rep(i, n) {
        in(c[i]);
        rep(j, k) in(a[i][j]);
    }

    map<vi, ll> dp, dp2;
    dp[vi(k)] = 0;

    rep(i, n) {
        dp2 = dp;
        fore(key, val, dp2) {
            vi nxt = key;

            rep(j, k) nxt[j] = min(nxt[j] + a[i][j], p);
            if (dp.count(nxt)) {
                dp[nxt] = min(dp[nxt], val + c[i]);
            } else {
                dp[nxt] = val + c[i];
            }
        }
    }

    ll ans = -1;
    if (dp.count(vi(k, p))) {
        ans = dp[vi(k, p)];
    }
    out(ans);
    return 0;
}
#endif

#else

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
template<typename T> void invec(T &x){ rep(i, sz(x)) cin >> x[i]; }
template<typename T> void invec2(T &x){ rep(i, sz(x)) invec(x[i]); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<typename T> void outvec(const vector<T>& v, char d = '\n'){ rep(i,sz(v)) cout << v[i] << (i == sz(v)-1 ? '\n' : d);}
#define yesno(x) cout << ((x) ? "Yes" : "No") << endl;
#define yes(x) if(x){ cout << "Yes" << endl; exit(0); }
#define no(x) if(x){ cout << "No" << endl; exit(0); }
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

#define INCLUDE_MAIN
#include __FILE__

#endif
