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
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

int main() {
    int n;
    in(n);
    vi p(n);
    vi c(n * 2);
    rep(i, n) in(p[i]);
    rep(i, n) {
        int d = (p[i] + n - i) % n;
        c[d]++;
        c[d + n]++;
    }

    int ans = 0;
    rep(i, 1, n * 2 - 1) {
        chmax(ans, c[i - 1] + c[i] + c[i + 1]);
    }

    out(ans);
    return 0;
}
