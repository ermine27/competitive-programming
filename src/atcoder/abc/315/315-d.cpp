#ifdef INCLUDE_MAIN

/*
愚直に判定すると計算量は O((H+W)HW) になるのでTLEする。
そこで各行・列が持っている要素を<要素、個数>の連想配列で持たせることで処理を高速化させる。
*/
int main() {
    int h, w, ans = 0;
    char c;
    in(h, w);
    vector<map<char, int>> cr(h), cc(w);
    rep(i, h) rep(j, w) {
        in(c);
        cr[i][c]++;
        cc[j][c]++;
    }

    bool ok;
    do {
        ok = false;

        vi dr, dc;
        rep(i, h) {
            if (cr[i].size() == 1 && cr[i].begin()->second > 1) {
                dr.push_back(i);
            }
        }
        rep(j, w) {
            if (cc[j].size() == 1 && cc[j].begin()->second > 1) {
                dc.push_back(j);
            }
        }

        if (dr.size() || dc.size()) {
            ok = true;
            rep(i, sz(dr)) {
                c = cr[dr[i]].begin()->first;
                cr[dr[i]].clear();
                rep(j, w) {
                    if (!cc[j].count(c))
                        continue;
                    cc[j][c]--;
                    if (cc[j][c] == 0) {
                        cc[j].erase(c);
                    }
                }
            }
            rep(j, sz(dc)) {
                c = cc[dc[j]].begin()->first;
                cc[dc[j]].clear();
                rep(i, h) {
                    if (!cr[i].count(c))
                        continue;
                    cr[i][c]--;
                    if (cr[i][c] == 0) {
                        cr[i].erase(c);
                    }
                }
            }
        }

    } while (ok);

    rep(i, h) {
        for (auto it = cr[i].begin(); it != cr[i].end(); it++) {
            ans += it->second;
        }
    }

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
