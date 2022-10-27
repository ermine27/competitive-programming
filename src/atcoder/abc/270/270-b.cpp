#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
using vi = vector<int>;
using vl = vector<long long>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

int main() {
    int x, y, z, ans;
    in(x, y, z);

    if (x < 0) {
        x *= -1;
        y *= -1;
        z *= -1;
    }

    if (x > 0 && (y > x || y < 0)) {
        out(x);
        return 0;
    }

    if (z > y) {
        ans = -1;
    } else {
        ans = abs(z) + (x - z);
    }

    out(ans);
    return 0;
}
