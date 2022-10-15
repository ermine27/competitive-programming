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
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

const ll mod = 1000000007;

ll modpow(ll x, ll n, ll mod) {
    ll ret = 1;

    while (n > 0) {
        if (n & 1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

int main() {
    ll n, q, ans = 0;
    in(n, q);
    vl a(n + 1);
    vi c(q + 1);
    rep(i, n) in(a[i + 1]);
    rep(i, q) in(c[i]);
    c[q] = 1;

    vl b(n);
    rep(i, 1, n) b[i] = modpow(a[i], a[i + 1], mod);

    vl s(n + 1);
    rep(i, 1, n) s[i + 1] = s[i] + b[i];

    int cur = 1;
    repe(i, 0, q) {
        int from = cur;
        int to = c[i];
        cur = to;
        if (from > to) swap(from, to);

        ans = (ans + s[to] - s[from]) % mod;
    }

    out(ans);
    return 0;
}
