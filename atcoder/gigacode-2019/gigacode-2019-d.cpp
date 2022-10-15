#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define _repe1(i,n) for(int i = 1; i <= (int)(n); ++i)
#define _repe2(i,s,n) for(int i = (int)(s); i <= (int)(n); ++i)
#define repe(...) _overload3(__VA_ARGS__, _repe2, _repe1)(__VA_ARGS__)
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

int main() {
    int h, w;
    ll k, v;
    in(h, w, k, v);
    vvls(a, h, w);
    vvls(s, h + 1, w + 1);
    rep(i, h) rep(j, w) in(a[i][j]);

    // 二次元累積和
    repe(i, h) repe(j, w) {
        s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i - 1][j - 1];
    }

    ll ans = 0;
    rep(x1, h) rep(y1, w) repe(x2, x1, h) repe(y2, y1, w) {
        ll area = (x2 - x1) * (y2 - y1);
        if (area == 0) continue;

        ll cost = (s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1]) + (area * k);
        if (cost <= v) {
            chmax(ans, area);
        } else {
            break;
        }
    }

    out(ans);
    return 0;
}
