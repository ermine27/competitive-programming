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
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using mii = map<int,int>;
using mll = map<ll,ll>;
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))
#define deg2rad(x) (x*M_PI/180.0)
#define rad2deg(x) (x*180.0/M_PI)
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
const int INF = 1.1e9;
const ll INFLL = 4.4e18;
const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

const int mod = 10007;

int main() {
    int n;
    in(n);
    string s;
    in(s);
    vi c(n);
    rep(i, n) {
        if (s[i] == 'J') c[i] = (1 << 2);
        if (s[i] == 'O') c[i] = (1 << 1);
        if (s[i] == 'I') c[i] = (1 << 0);
    }

    vvis(dp, n + 1, 1 << 3);
    dp[0][1 << 2] = 1;

    rep(i, n) {
        rep(j, 1 << 3) {
            // 次の1行はなくても多分ACする
            if (!dp[i][j]) continue;

            rep(k, 1 << 3) {
                if (!(j & k) || !(c[i] & k)) continue;
                dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % mod;
            }
        }
    }

    int ans = 0;
    rep(i, 1 << 3) {
        ans = (ans + dp[n][i]) % mod;
    }

    out(ans);
    return 0;
}
