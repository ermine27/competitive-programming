#ifdef INCLUDE_MAIN

/*
解法１
満足度の定義の2パターンを場合分けして、それぞれの最大を求めて大きいほうを答えとして出力する。
*/
int main() {
    int n, ans = -1;
    in(n);
    vvi fs(n);
    rep(i, n) {
        int f, s;
        in(f, s);
        fs[f - 1].push_back(s);
    }

    rep(i, n) { sort(all(fs[i]), greater<int>{}); }

    rep(i, n) {
        int size = sz(fs[i]);
        if (size >= 2) {
            chmax(ans, fs[i][0] + fs[i][1] / 2);
        }
    }

    int max1 = -1, max2 = -1;
    rep(i, n) {
        if (sz(fs[i]) == 0)
            continue;

        if (fs[i][0] > max1) {
            max2 = max1;
            max1 = fs[i][0];
        } else {
            if (fs[i][0] > max2) {
                max2 = fs[i][0];
            }
        }
    }
    chmax(ans, max1 + max2);

    out(ans);
    return 0;
}

/*
解法２
どちらのパターンでも美味しさが一番大きいアイスは選ぶことになる。
なので、1つ目は美味しさが最大のもので固定して、もう１つを２つのパターンで分岐して合計の大きいほうを答えとして出力する。
*/
int main2() {
    int n, ans = -1;
    in(n);
    vi f(n), s(n);
    int maxno = -1, maxf = -1;
    rep(i, n) {
        in(f[i], s[i]);
        if (chmax(ans, s[i])) {
            maxno = i;
            maxf = f[i];
        }
    }
    int second = -1;
    rep(i, n) {
        if (i == maxno)
            continue;
        if (f[i] == maxf) {
            chmax(second, s[i] / 2);
        } else {
            chmax(second, s[i]);
        }
    }

    ans += second;
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
