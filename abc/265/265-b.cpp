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
using vvi = vector<vi>;
using vvl = vector<vl>;
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)
template<typename... T> void in(T&... a){ (cin >> ... >> a); }

int main() {
    int n, m;
    ll t;
    in(n, m, t);
    vls(a, n - 1);
    rep(i, n - 1) in(a[i]);
    map<int, ll> xy;
    rep(i, m) {
        int xi, yi;
        in(xi, yi);
        xy[xi - 1] = yi;
    }

    rep(i, n - 1) {
        t -= a[i];
        if (t <= 0) {
            cout << "No";
            return 0;
        }

        t += xy[i + 1];
    }

    cout << "Yes";
    return 0;
}
