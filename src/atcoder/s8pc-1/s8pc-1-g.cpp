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
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

const ll INFLL = 1e18;

int main() {
    int n, m;
    in(n, m);
    vvls(g, n, n, INFLL);
    vvls(gt, n, n, INFLL);
    rep(i, m) {
        ll s, t, d, tm;
        in(s, t, d, tm);
        --s;
        --t;
        g[s][t] = d;
        g[t][s] = d;
        gt[s][t] = tm;
        gt[t][s] = tm;
    }

    vvls(dp, 1 << n, n, INFLL);
    vvls(cnt, 1 << n, n);
    vvls(time, 1 << n, n);

    dp[0][0] = 0;
    cnt[0][0] = 1;

    rep(s, 1 << n) {
        rep(to, n) {
            rep(from, n) {
                if (to == from) continue;
                if (s != 0 && !(s & (1 << from))) continue;
                if ((s & (1 << to)) == 0) {
                    if (time[s][from] + g[from][to] > gt[from][to]) {
                        continue;
                    }

                    int si = s | (1 << to);
                    if (dp[si][to] == dp[s][from] + g[from][to]) {
                        cnt[si][to] += cnt[s][from];
                    } else if (chmin(dp[si][to], dp[s][from] + g[from][to])) {
                        cnt[si][to] = cnt[s][from];
                        time[si][to] = time[s][from] + g[from][to];
                    }
                }
            }
        }
    }

    ll ans = dp[(1 << n) - 1][0];
    if (ans == INFLL) {
        out("IMPOSSIBLE");
    } else {
        out(ans, cnt[(1 << n) - 1][0]);
    }

    return 0;
}
