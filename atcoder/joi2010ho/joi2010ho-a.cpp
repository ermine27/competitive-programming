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

const int mod = 1e5;

int main() {
    int n, m;
    in(n, m);
    vi d(n - 1);
    vi a(m);
    vl c(n);
    rep(i, n - 1) in(d[i]);
    rep(i, m) in(a[i]);
    rep(i, n - 1) c[i + 1] = c[i] + d[i];

    ll ans = 0;
    int cur = 0;
    rep(i, m) {
        int next = cur + a[i];
        ans = (ans + abs(c[next] - c[cur])) % mod;
        cur = next;
    }

    out(ans);
    return 0;
}
