#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename T> T power(T x) { return x * x; }
template<typename T> T power(T x, int n) { T a=1; rep(i,n) a *= x; return a; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

int main() {
    int n, m;
    in(n, m);

    vector<double> x(n + m), y(n + m), r(n + m);
    rep(i, n) in(x[i], y[i], r[i]);
    rep(i, m) in(x[i + n], y[i + n]);

    double ans = 1e9;
    rep(i, n) chmin(ans, r[i]);
    rep(i, n, n + m) {
        rep(j, n + m) {
            if (i == j) continue;

            double d, dist = sqrt(power(x[i] - x[j]) + power(y[i] - y[j]));
            if (j < n) {
                d = min(r[j], dist - r[j]);
            } else {
                d = dist / 2;
            }
            chmin(ans, d);
        }
    }

    cout << fixed << setprecision(10);
    out(ans);
    return 0;
}
