#ifdef INCLUDE_MAIN

/*
解き方１（コンテスト中に考えた方針）
操作を行う前と後で、Aの総和は変わらない。
最小値と最大値の差を1以下にするには、操作を行った後の数列の値は必ず平均値か平均値+1のどちらかになる。
増やす数の総和と減らす数の総和を調べていく。
ただし、減らす数の時は、平均値が整数の場合は平均値との差をとり、端数が出る場合は平均値+1との差を取る。
最後に、増やす数の総和と減らす数の総和のうち、大きい方が答えになる。
*/
int main2() {
    int n;
    in(n);
    vl a(n);
    invec(a);
    ll sum = accumulate(all(a), 0LL);
    ll mid = sum / n;
    ll mid2 = mid;
    if (sum % n > 0)
        mid2++;

    ll suml = 0LL, sumr = 0LL;
    rep(i, n) {
        if (a[i] <= mid)
            suml += mid - a[i];
        else
            sumr += a[i] - mid2;
    }
    ll ans = max(suml, sumr);
    out(ans);
    return 0;
}

/*
解き方２（解説動画より）
操作を行う前と後で、Aの総和は変わらない。
ここから最終的なAの要素の数は一意に求まる。(これをBとする)
AとBをそれぞれソートしてから、Σ|Ai-Bi|
で差分の総和を求めて、それを2で割ったものが必要な操作回数になる。
*/
int main() {
    int n;
    in(n);
    vl a(n);
    invec(a);
    sort(all(a));
    ll sum = accumulate(all(a), 0LL);
    int div = sum / n;
    int mod = sum % n;
    vl b(n, div);
    rep(i, mod) b[i]++;
    sort(all(b));
    ll ans = 0;

    rep(i, n) { ans += abs(a[i] - b[i]); }
    ans /= 2;
    out(ans);
    return 0;
}

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
