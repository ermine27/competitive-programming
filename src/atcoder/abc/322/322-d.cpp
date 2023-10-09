#ifdef INCLUDE_MAIN

// 左にr*90度、回転する
vvi rotate(vvi x, int r) {
    rep(k, r) {
        vvi x2 = x;
        rep(i, 4) rep(j, 4) x2[i][j] = x[j][3 - i];
        x = x2;
    }
    return x;
}

// 平行移動する
// 座標のデータは参照渡しとし、結果は並行で来たか否かの成否を返す
bool parallelMove(vvi& p, int x, int y) {
    vvi pt(4, vi(4));
    rep(i, 4) {
        rep(j, 4) {
            if (p[i][j]) {
                int nx = i + x;
                int ny = j + y;
                if (nx < 0 || nx > 3 || ny < 0 || ny > 3)
                    return false;
                pt[nx][ny] = 1;
            }
        }
    }

    p = pt;
    return true;
}

int main() {
    vector<vvi> p(3, vvi(4, vi(4)));
    rep(k, 3) {
        rep(i, 4) {
            rep(j, 4) {
                char c;
                in(c);
                if (c == '#')
                    p[k][i][j] = 1;
            }
        }
    }

    vector<vector<vvi>> q(3);

    // ３つのポリオミノそれぞれについて配置可能なパターンを洗い出す
    rep(k, 3) {
        rep(r, 4) {
            vvi pt = rotate(p[k], r);
            for (int i = -3; i <= 3; i++) {
                for (int j = -3; j <= 3; j++) {
                    vvi pt2 = pt;
                    if (parallelMove(pt2, i, j))
                        q[k].push_back(pt2);
                }
            }
        }
    }

    // 洗い出した配置パターンを全探索する
    fore(p0, q[0]) {
        fore(p1, q[1]) {
            fore(p2, q[2]) {
                bool ok = true;
                rep(i, 4) rep(j, 4) {
                    if (p0[i][j] + p1[i][j] + p2[i][j] != 1)
                        ok = false;
                }
                yes(ok);
            }
        }
    }

    no(true);
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
