#ifdef INCLUDE_MAIN

/*
解法その２
問題文にある、
・N頂点N辺の有効グラフ
・i番目の辺は頂点iから頂点Aiに伸びる
ということは全ての頂点の出次数が１であり、つまり全ての頂点の入次数が1以上になることが分かる。
よって、任意の点から遷移を繰り返すと必ず閉路に辿り着く。
この条件下では閉路は以下の方法で求められる。
１）任意の点（点１）から遷移を繰り返して2度辿る点を見つける。
　　この時点でM（有向閉路の頂点数）は分かるので出力する。
２）１で求めた点が閉路の基点になるので、そこから1週するまで順に辿りながら頂点を出力する。
*/
int main2() {
    int n;
    in(n);
    vi a(n);
    rep(i, n) {
        in(a[i]);
        a[i]--;
    }

    vi dest(n);
    int cur = 0;
    int cnt = 1;
    while (!dest[cur]) {
        dest[cur] = cnt;
        cnt++;
        cur = a[cur];
    }

    int num = cnt - dest[cur];
    cout << num << endl;

    rep(i, num) {
        cout << cur + 1 << ' ';
        cur = a[cur];
    }

    cout << endl;
    return 0;
}

/*
コンテスト中に考えたソース
Nは大きいが取り敢えず各点についてDFSで順番に辿っていって、周期性が見つかったらその区間を出力させる
*/
int main() {
    int n;
    in(n);
    vvi g(n);
    rep(i, n) {
        int a;
        in(a);
        g[i].push_back(a - 1);
    }

    vi route;
    vi vst(n);
    vi used(n);

    auto dfs = [&](auto self, int x) -> void {
        if (vst[x]) {
            auto f = find(all(route), x);
            int pos = f - route.begin();
            cout << (route.size() - pos - 1) << endl;
            for (auto it = f; it != route.end() - 1; it++) {
                cout << (*it + 1) << ' ';
            }
            cout << endl;

            exit(0);
        }

        vst[x] = 1;

        for (int t : g[x]) {
            route.push_back(t);
            self(self, t);
            route.pop_back();
        }

        return;
    };

    rep(i, n) {
        rep(j, n) vst[i] = 0;
        route = {i};

        dfs(dfs, i);
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
