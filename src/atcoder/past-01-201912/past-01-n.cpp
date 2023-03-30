/*
第一回 アルゴリズム実技検定  N - 整地

座標圧縮をした上で、累積和を取る。
各境界において金額を計算する。
ある地点xにおいて、右側の境界x+cは二分探索で探す。
金額は区間内に重なっている石を数えるのが大変なので、全体から区間外にある石を引き算して計算する。
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
    int n, w, c;
    in(n, w, c);
    vl l(n), r(n), p(n);
    set<int> idx;
    idx.insert(0);
    mll ml, mr;
    ll tot = 0;
    rep(i, n) {
        in(l[i], r[i], p[i]);
        idx.insert(l[i]);
        idx.insert(r[i]);
        ml[l[i]] += p[i];
        mr[r[i]] += p[i];
        tot += p[i];
    }

    mll cl, cr;
    cl[w] = 0;
    cr[0] = 0;

    for (auto it = ml.rbegin(); it != ml.rend(); it++) {
        cl[it->first] = cl[cl.begin()->first] + it->second;
    }

    for (auto it = mr.begin(); it != mr.end(); it++) {
        cr[it->first] = cr[cr.rbegin()->first] + it->second;
    }

    ll ans = INFLL;

    fore(x, idx) {
        if (x + c > w)
            continue;

        auto il = cr.upper_bound(x);
        il--;
        auto ir = cl.lower_bound(x + c);

        ll score = tot - il->second - ir->second;
        chmin(ans, score);
    }

    out(ans);
    return 0;
}
