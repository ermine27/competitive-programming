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

#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)

template<typename... T> void in(T& ... a){ (cin >> ... >> a); }
template<typename T> void vecin(T &x, int n){ rep(i,n) cin >> x[i]; }
template<typename T> void vecin(T &x){ vecin(x, sz(x)); }


int main() {
    int n;
    in(n);
    vis(c,n);
    vecin(c);

    vis(dp,n+1,INT_MAX);
    dp[0] = -1;
    rep(i,n){
        int idx = lower_bound(all(dp), c[i]) - dp.begin();
        dp[idx] = c[i];
    }

    int ans = n - (lower_bound(all(dp), INT_MAX) - dp.begin() - 1);
    cout << ans << endl;
    return 0;
}
