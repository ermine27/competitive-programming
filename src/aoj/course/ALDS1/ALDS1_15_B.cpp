#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }

int main() {
    int n, w;
    in(n, w);
    vector<tuple<int, int, double>> item(n);

    rep(i, n) {
        int vi, wi;
        double ui;
        in(vi, wi);
        ui = 1.0 * vi / wi;
        item[i] = make_tuple(vi, wi, ui);
    }

    sort(all(item), [](tuple<int, int, double> a, tuple<int, int, double> b) {
        return get<2>(a) > get<2>(b);
    });

    double ans = 0.0;
    int i = 0;
    while (w > 0) {
        int vi, wi;
        double ui;
        tie(vi, wi, ui) = item[i];

        int wt = min(w, wi);
        ans += 1.0 * wt * ui;
        w -= wt;
        ++i;
    }

    printf("%.10f\n", ans);
    return 0;
}
