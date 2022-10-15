/*
二次元累積和
*/

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
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

int main() {
    int m, n, k;
    in(m, n, k);
    vector<string> g(m);
    rep(i, m) in(g[i]);

    vvis(sj, m + 1, n + 1, 0);
    vvis(so, m + 1, n + 1, 0);
    vvis(si, m + 1, n + 1, 0);

    rep(i, m) rep(j, n) {
        char gg = g[i][j];

        sj[i + 1][j + 1] = sj[i + 1][j] + sj[i][j + 1] - sj[i][j];
        so[i + 1][j + 1] = so[i + 1][j] + so[i][j + 1] - so[i][j];
        si[i + 1][j + 1] = si[i + 1][j] + si[i][j + 1] - si[i][j];

        if (gg == 'J') ++sj[i + 1][j + 1];
        if (gg == 'O') ++so[i + 1][j + 1];
        if (gg == 'I') ++si[i + 1][j + 1];
    }

    rep(i, k) {
        int x1, y1, x2, y2, aj, ao, ai;
        in(x1, y1, x2, y2);
        --x1;
        --y1;

        aj = sj[x2][y2] - sj[x1][y2] - sj[x2][y1] + sj[x1][y1];
        ao = so[x2][y2] - so[x1][y2] - so[x2][y1] + so[x1][y1];
        ai = si[x2][y2] - si[x1][y2] - si[x2][y1] + si[x1][y1];

        out(aj, ao, ai);
    }

    return 0;
}
