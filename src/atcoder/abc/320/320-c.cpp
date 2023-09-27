#ifdef INCLUDE_MAIN

int main() {
    int m, ans = INF;
    in(m);
    vector<string> s(3);
    rep(i, 3) {
        in(s[i]);
        s[i] += s[i] + s[i];
    }

    rep(i, m * 3) {
        rep(j, m * 3) {
            rep(k, m * 3) {
                if (i != j && j != k && k != i && s[0][i] == s[1][j] && s[0][i] == s[2][k]) {
                    chmin(ans, max({i, j, k}));
                }
            }
        }
    }

    if (ans == INF)
        ans = -1;
    out(ans);
    return 0;
}

int main2() {
    int m;
    in(m);
    int ans = INF;
    vvi s(3, vi(m * 3));
    rep(i, 3) {
        string ss;
        in(ss);
        rep(j, m) { s[i][j] = s[i][j + m] = s[i][j + m * 2] = ss[j] - '0'; }
    }

    vi p = {0, 1, 2};
    do {
        rep(k, 10) {
            int cnt = -1;
            rep(i, 3) {
                cnt++;
                while (cnt < m * 3 && s[p[i]][cnt] != k) {
                    cnt++;
                    if (cnt >= m * 3) {
                        cnt = INF;
                        break;
                    }
                }
            }

            chmin(ans, cnt);
        }
    } while (next_permutation(all(p)));

    if (ans == INF)
        ans = -1;
    out(ans);
    return 0;
}

// リールが4つ以上ある場合にも対応。一般化。
int main3() {
    int m, ans = INF;
    in(m);
    vvi s(3, vi(m * 3));
    rep(i, 3) {
        string ss;
        in(ss);
        rep(j, m) { s[i][j] = s[i][j + m] = s[i][j + m * 2] = ss[j] - '0'; }
    }

    auto dfs = [&](auto self, int k, bitset<3> x, int cur) -> void {
        if (x.count() == 3) {
            chmin(ans, cur);
            return;
        }

        rep(i, 3) {
            if (x[i])
                continue;
            int pos = -1;
            rep(j, cur + 1, m * 3) {
                if (s[i][j] == k) {
                    pos = j;
                    break;
                }
            }
            if (pos == -1) {
                return;
            }

            x.set(i);
            self(self, k, x, pos);
            x.reset(i);
        }

        return;
    };

    rep(k, 10) { dfs(dfs, k, 0, -1); }

    if (ans == INF)
        ans = -1;
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
