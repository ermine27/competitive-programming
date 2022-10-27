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
using vl = vector<ll>;
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

int main() {
    int n, m;
    in(n, m);
    vl p(m), a(n), b(n), c(n);
    rep(i, m) in(p[i]);
    repe(i, n - 1) in(a[i], b[i], c[i]);

    vi imos(n + 1);
    int cur = p[0];
    rep(i, 1, m) {
        int dst = p[i];
        int left = cur, right = dst;
        cur = dst;

        if (left > right) swap(left, right);
        ++imos[left];
        --imos[right];
    }

    ll ans = 0;
    cur = 0;
    rep(i, 1, n) {
        cur += imos[i];
        ans += min(a[i] * cur, b[i] * cur + c[i]);
    }

    out(ans);
    return 0;
}
