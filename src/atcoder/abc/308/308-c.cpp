#ifdef INCLUDE_MAIN

/*
iの成功率Piと、jの成功率Pjを比較する
　Pi = Ai / (Ai+Bi)
　Pj = Aj / (Aj+Bj)

解法１）
Pi,Pjをそのまま計算して比較する
浮動小数点型になるので丸め誤差が起きないように long double にする。

解法２）
整数で比較する
それぞれの右辺を分母を払って Ai*(Aj+Bj) と Aj*(Ai+Bi) の大小を比較する
long long側でないとオーバーフローする。
*/

#if 0
int main() {
    int n;
    in(n);
    vector<pair<int, long double>> p(n);

    rep(i, n) {
        int a, b;
        in(a, b);
        p[i] = {i + 1, (long double)a / (a + b)};
    }

    sort(all(p), [](pair<int, long double> a, pair<int, long double> b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    });

    rep(i, n) { cout << p[i].first << ' '; }
    cout << endl;
    return 0;
}
#endif

#if 1
int main() {
    int n;
    in(n);
    vector<pll> c(n);

    rep(i, n) {
        int a, b;
        in(a, b);
        c[i] = {a, a + b};
    }

    vi p(n);
    iota(all(p), 0);
    stable_sort(p.begin(), p.end(),
                [&](int a, int b) { return c[a].first * c[b].second > c[b].first * c[a].second; });
    rep(i, n) { cout << p[i] + 1 << ' '; }
    cout << endl;
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
