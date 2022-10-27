#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

const int INF = INT_MAX;

int main() {
    int h, w;
    in(h, w);
    vvis(c, 10, 10);
    rep(i, 10) rep(j, 10) in(c[i][j]);

    rep(k, 10) {
        rep(i, 10) {
            if (c[i][k] == INF) continue;
            rep(j, 10) {
                if (c[k][j] == INF) continue;
                chmin(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    int ans = 0;
    rep(i, h * w) {
        int aa;
        in(aa);
        if (aa > -1) ans += c[aa][1];
    }

    out(ans);
    return 0;
}
