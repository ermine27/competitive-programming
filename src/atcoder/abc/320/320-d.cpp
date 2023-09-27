#ifdef INCLUDE_MAIN

struct Edge {
    int to, x, y;
    Edge(int to, int x, int y) : to(to), x(x), y(y) {}
};

int main() {
    int n, m;
    in(n, m);
    vector<vector<Edge>> g(n);
    vl ansx(n, INF), ansy(n, INF);
    ansx[0] = ansy[0] = 0;
    rep(i, m) {
        int a, b, x, y;
        in(a, b, x, y);
        a--;
        b--;
        g[a].emplace_back(b, x, y);
        g[b].emplace_back(a, -x, -y);
    }

    auto dfs = [&](auto self, int t) -> void {
        for (auto [u, dx, dy] : g[t]) {
            if (ansx[u] != INF)
                continue;
            ansx[u] = ansx[t] + dx;
            ansy[u] = ansy[t] + dy;
            self(self, u);
        }
    };

    dfs(dfs, 0);

    rep(i, n) {
        if (ansx[i] == INF) {
            cout << "undecidable" << endl;
        } else {
            cout << ansx[i] << ' ' << ansy[i] << endl;
        }
    }
    return 0;
}

// structを使わずに実装
int main2() {
    int n, m;
    in(n, m);
    vl a(m), b(m), x(m), y(m), ansx(n), ansy(n), v(n);
    map<pii, pii> p;
    vvi g(n);
    rep(i, m) {
        int a, b, x, y;
        in(a, b, x, y);
        a--;
        b--;
        p[{a, b}] = {x, y};
        p[{b, a}] = {-x, -y};
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto dfs = [&](auto self, int x) -> void {
        v[x] = 1;
        for (int t : g[x]) {
            if (v[t])
                continue;
            ansx[t] = ansx[x] + p[{x, t}].first;
            ansy[t] = ansy[x] + p[{x, t}].second;
            self(self, t);
        }
        return;
    };

    dfs(dfs, 0);

    rep(i, n) {
        if (!v[i]) {
            cout << "undecidable" << endl;
        } else {
            cout << ansx[i] << ' ' << ansy[i] << endl;
        }
    }

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
