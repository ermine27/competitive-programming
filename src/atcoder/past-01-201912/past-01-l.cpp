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
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
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

vector<vector<double>> dist;
vi x, y, c, k;
int n, m, s;
vector<bool> vst;

struct Tower {
    int kind, color;
    double x, y;
};
vector<Tower> tower;

double prim(bitset<5> bs) {
    double weight = 0;
    vst.assign(s, 0);
    vst[0] = true;

    int use_small = bs.count();

    // 大きい塔＋あらかじめ使うと決めた小さい塔を全て通ったら終了
    while (count(all(vst), true) < n + use_small) {
        int next = -1;
        double min_weight = INT_MAX;
        rep(i, s) {
            if (!vst[i])
                continue;
            if (i >= n && !bs[i - n])
                continue;

            rep(j, s) {
                if (vst[j] || dist[i][j] < 0)
                    continue;

                if (j >= n && !bs[j - n])
                    continue;

                if (chmin(min_weight, dist[i][j])) {
                    next = j;
                }
            }
        }

        vst[next] = true;
        weight += min_weight;
    }

    return weight;
}

int main() {
    in(n, m);
    s = n + m;
    tower.resize(s);

    rep(i, n) {
        tower[i].kind = 0;
        in(tower[i].x, tower[i].y, tower[i].color);
    }
    rep(j, n, s) {
        tower[j].kind = 1;
        in(tower[j].x, tower[j].y, tower[j].color);
    }

    dist.resize(s, vector<double>(s));
    rep(i, s) {
        rep(j, s) {
            dist[i][j] = sqrt((tower[i].x - tower[j].x) * (tower[i].x - tower[j].x) +
                              (tower[i].y - tower[j].y) * (tower[i].y - tower[j].y));
            if (tower[i].color != tower[j].color) {
                dist[i][j] *= 10;
            }
        }
    }

    double ans = 1e9;

    // 小さい塔についてどれを使うかはbit全探索する
    rep(i, 1 << m) { chmin(ans, prim(bitset<5>(i))); }

    printf("%.10f\n", ans);
    return 0;
}
