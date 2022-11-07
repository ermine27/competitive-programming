#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define sz(x) ((int)(x).size())
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }

int main() {
    string t, p;
    in(t, p);

    int tlen = sz(t);
    int plen = sz(p);
    rep(i, tlen - plen + 1) {
        if (t.substr(i, plen) == p) out(i);
    }

    return 0;
}
