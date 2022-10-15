/*
2本の対角線を線分として、線分の交差判定をする

参考
https://qiita.com/zu_rin/items/e04fdec4e3dec6072104
*/
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
#define per(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define perf(i,n) for(int i = (int)(n); i >= 1; --i)
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

bool check(vi x, vi y) {
    double f, g;
    f = (x[0] - x[1]) * (y[2] - y[0]) - (y[0] - y[1]) * (x[2] - x[0]);
    g = (x[0] - x[1]) * (y[3] - y[0]) - (y[0] - y[1]) * (x[3] - x[0]);

    return f * g < 0;
}

int main() {
    vi x(4), y(4);
    rep(i, 4) in(x[i], y[i]);

    swap(x[1], x[2]);
    swap(y[1], y[2]);

    if (!check(x, y)) {
        out("No");
        return 0;
    }

    swap(x[0], x[2]);
    swap(y[0], y[2]);
    swap(x[1], x[3]);
    swap(y[1], y[3]);

    if (!check(x, y)) {
        out("No");
        return 0;
    }

    out("Yes");
    return 0;
}
