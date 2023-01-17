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

int main() {
    int n;
    in(n);
    vvi a(n - 1);
    rep(i, n - 1) {
        rep(j, i + 1, n) {
            int t;
            in(t);
            a[i].push_back(t);
        }
    }

    int ans = -1e9;

    // 組み合わせはビット全探索をそのまま行っても計算量は十分足りる。 (3^10 = 59049)
    // 2つ目と3つ目で重複しないようにするほうが大変
    rep(i, 1 << n) {
        vector<bitset<10>> bs(3);
        bs[0] = i;
        rep(j, 1 << n) {
            bs[1] = j;
            rep(k, 1 << n) {
                bs[2] = k;

                bool check = true;
                if ((int)(bs[0].count() + bs[1].count() + bs[2].count()) != n)
                    check = false;
                rep(s, n) {
                    if (bs[0][s] & bs[1][s] || bs[1][s] & bs[2][s] || bs[2][s] & bs[0][s])
                        check = false;
                }
                if (!check)
                    continue;

                int score = 0;
                rep(s, 3) {
                    rep(t, n - 1) {
                        rep(u, t + 1, n) {
                            if (bs[s][t] & bs[s][u]) {
                                score += a[t][u - t - 1];
                            }
                        }
                    }
                }
                chmax(ans, score);
            }
        }
    }

    out(ans);
    return 0;
}
