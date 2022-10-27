/*
4つの点Pのうちの一つ(Pt)を除いた残りのPからできる三角形内にPtがあるかをチェックし、存在すれば凹な四角形。
PtをP1、P2、P3、P4と変えていき、全ての4パターンについて調べる

参考
http://popopondelion.blog.fc2.com/blog-entry-7.html
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

int main() {
    vi x(4), y(4);
    rep(i, 4) in(x[i], y[i]);

    rep(i, 4) {
        double ax = x[i % 4], bx = x[(i + 1) % 4], cx = x[(i + 2) % 4], dx = x[(i + 3) % 4];
        double ay = y[i % 4], by = y[(i + 1) % 4], cy = y[(i + 2) % 4], dy = y[(i + 3) % 4];

        double abXad = (bx - ax) * (dy - ay) - (by - ay) * (dx - ax);
        double bcXbd = (cx - bx) * (dy - by) - (cy - by) * (dx - bx);
        double caXcd = (ax - cx) * (dy - cy) - (ay - cy) * (dx - cx);

        if ((abXad > 0.0 && bcXbd > 0.0 && caXcd > 0.0) || (abXad < 0.0 && bcXbd < 0.0 && caXcd < 0.0)) {
            out("No");
            return 0;
        }
    }

    out("Yes");
    return 0;
}
