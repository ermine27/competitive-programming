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
// const int INF = 1.1e9;
const int INF = 1.01e9;
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

// DPの値をpair型で持たせる場合
#if 1
int main() {
    int n, q;
    in(n);
    vl a(n);
    invec(a);

    // c++17：クラステンプレートのテンプレート引数推論
    // vector<vector<pll>> dp(n, vector<pll>(n,pll(INF,0)));
    vector dp(n, vector<pll>(n, pll(INF, 0)));

    rep(i, n) dp[i][i] = pll(0, 0);

    rep(i, n) {
        string s;
        in(s);
        rep(j, n) {
            if (s[j] == 'Y') {
                // 価値を負数で持っておくことで、pair側の大小比較が行えるようになる
                dp[i][j] = pll(1, -a[j]);
            }
        }
    }

    // 全点対最短経路を求める（ワーシャル・フロイド法）... O(N^3)
    rep(k, n) {
        rep(i, n) {
            // この一文を入れても速度は早くならない。不要。
            // if (dp[i][k].first == INF) continue;
            rep(j, n) {
                pll tmp = dp[k][j];
                tmp.first = dp[i][k].first + dp[k][j].first;
                tmp.second = dp[i][k].second + dp[k][j].second;
                chmin(dp[i][j], tmp);
            }
        }
    }

    in(q);
    rep(i, q) {
        int u, v;
        in(u, v);
        u--;
        v--;
        if (dp[u][v].first == INF) {
            out("Impossible");
        } else {
            ll value = a[u] - dp[u][v].second;
            out(dp[u][v].first, value);
        }
    }

    return 0;
}
#endif

// DPの値を2つ別々に持たせる場合
#if 0
int main() {
    int n, q;
    in(n);
    vl a(n);
    invec(a);

    vvis(dps, n, n, INF);
    vvls(dpv, n, n, 0);
    rep(i, n) dps[i][i] = 0;

    rep(i, n) {
        string s;
        in(s);
        rep(j, n) {
            if (s[j] == 'Y') {
                dps[i][j] = 1;
                dpv[i][j] = a[j];
            }
        }
    }

    // 全点対最短経路を求める（ワーシャル・フロイド法）... O(N^3)
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                int u1 = dps[i][k] + dps[k][j];
                int u2 = dps[i][j];
                ll v1 = dpv[i][k] + dpv[k][j];
                ll v2 = dpv[i][j];

                if (u1 < u2 || (u1 == u2 && v1 > v2)) {
                    dps[i][j] = u1;
                    dpv[i][j] = v1;
                }
            }
        }
    }

    in(q);
    rep(i, q) {
        int u, v;
        in(u, v);
        u--;
        v--;
        if (dps[u][v] == INF) {
            out("Impossible");
        } else {
            ll value = a[u] + dpv[u][v];
            out(dps[u][v], value);
        }
    }

    return 0;
}
#endif
