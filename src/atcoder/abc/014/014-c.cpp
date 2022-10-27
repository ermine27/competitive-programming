// いもす法

#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
using vi = vector<int>;
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

const int COLORS = 1e6 + 1;

int main() {
    int n, a, b;
    in(n);
    vi imos(COLORS + 1);

    rep(i, n) {
        in(a, b);
        ++imos[a];
        --imos[b + 1];
    }

    int cur = 0, ans = 0;
    rep(i, COLORS) {
        cur += imos[i];
        chmax(ans, cur);
    }

    out(ans);
    return 0;
}
