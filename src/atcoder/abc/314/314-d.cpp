#ifdef INCLUDE_MAIN

/*
方法１
クエリを先読みして、t=2or3のクエリは一番最後のものだけを実行する
*/
int main() {
    int n, q;
    string s;
    in(n, s, q);

    vi t(q), x(q);
    vector<char> c(q);
    int cmd_no = -1;
    int cmd_type = -1;
    rep(i, q) {
        in(t[i], x[i], c[i]);
        if (t[i] != 1) {
            cmd_no = i;
            cmd_type = t[i];
        }
    }

    rep(i, q) {
        if (t[i] == 1) {
            s[x[i] - 1] = c[i];
        } else {
            if (i == cmd_no) {
                if (cmd_type == 2) {
                    rep(j, n) s[j] = tolower(s[j]);
                }
                if (cmd_type == 3) {
                    rep(j, n) s[j] = toupper(s[j]);
                }
            }
        }
    }

    out(s);
    return 0;
}

/*
方法２
クエリの先読みを行わずに方法1と同じことを実現させる
Sの各要素について最後に更新したタイミングの情報を持つようにし、
t=1のクエリで更新をしつつ、こちらも更新をする。
最後にt=2or3のクエリを実行する際に、それ以降のタイミングでt=1で更新がされていない要素のみ変更を行う
*/
int main2() {
    int n, q, t, x, t2 = 0, lst2 = -1;
    string s;
    char c;
    in(n, s, q);
    vi lst(n);

    rep(i, q) {
        in(t, x, c);
        if (t == 1) {
            x--;
            s[x] = c;
            lst[x] = i;
        } else {
            t2 = t;
            lst2 = i;
        }
    }

    rep(i, n) {
        if (lst[i] < lst2) {
            if (t2 == 2) {
                s[i] = tolower(s[i]);
            }
            if (t2 == 3) {
                s[i] = toupper(s[i]);
            }
        }
    }

    out(s);
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
