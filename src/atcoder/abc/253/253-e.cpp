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
using vl = vector<long long>;
using vvl = vector<vl>;
using mii = map<int,int>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

const int mod998244353 = 998244353;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vvl dp(n, vl(m + 1));

    repe(i, m) dp[0][i] = 1;

    rep(i, n - 1) {
        vl c(m + 1);
        rep(j, m) c[j + 1] = (c[j] + dp[i][j + 1]);

        repe(j, m) {
            if (k == 0) {
                dp[i + 1][j] = (dp[i][j] * m) % mod998244353;
                continue;
            }

            dp[i + 1][j] = (c[m] - (c[min(m, j + k - 1)] - c[max(0, j - k)])) % mod998244353;
        }
    }

    ll ans = 0;
    repe(j, m) ans = (ans + dp[n - 1][j]) % mod998244353;
    cout << ans << endl;
}
