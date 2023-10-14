#ifdef INCLUDE_MAIN

/*
比較関数を自作する方法
*/

// こっちはWAが出るので書き方が間違ってる
bool comp2(pii a, pii b) {
    if (a.second != b.second)
        return a.first > b.first;
    return a.second < b.second;
}
// 比較関数
bool comp(pii a, pii b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main() {
    int n;
    in(n);
    vi w(n);
    rep(i, n) {
        string s;
        in(s);
        rep(j, n) {
            if (s[j] == 'o')
                w[i]++;
        }
    }
    vector<pii> s(n);
    rep(i, n) s[i] = {w[i], i + 1};
    sort(all(s), comp);
    rep(i, n) cout << s[i].second << ' ';
    cout << endl;
    return 0;
}

/*
安定ソート：stable_sortを使う
*/
int main2() {
    int n;
    in(n);
    vi w(n);
    rep(i, n) {
        string s;
        in(s);
        rep(j, n) {
            if (s[j] == 'o')
                w[i]++;
        }
    }
    vector<pii> s(n);
    rep(i, n) s[i] = {w[i], i + 1};

    stable_sort(all(s), [&](pii a, pii b) { return a.first > b.first; });

    rep(i, n) cout << s[i].second << ' ';
    cout << endl;
    return 0;
}

/*
勝ち数の降順、プレイヤー番号の昇順の順で並べたいが、
勝ち数を-1倍すれば昇順だけで並べられる
*/
int main3() {
    int n;
    in(n);
    vi w(n);
    rep(i, n) {
        string s;
        in(s);
        rep(j, n) {
            if (s[j] == 'o')
                w[i]++;
        }
    }
    vector<pii> s(n);
    rep(i, n) s[i] = {-1 * w[i], i + 1};
    sort(all(s));
    rep(i, n) cout << s[i].second << ' ';
    cout << endl;
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
