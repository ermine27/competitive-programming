#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)
using ll = long long;
using vi = vector<int>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

vi primeFactorization(ll x) {
    ll k = x;
    vi ans;
    for (ll i = 2; i * i <= k; ++i) {
        while (x % i == 0) {
            x /= i;
            ans.push_back(i);
        }
    }
    if (x > 1) ans.push_back(x);

    return ans;
}

int main() {
    int n;
    in(n);
    vi ans = primeFactorization(n);

    cout << n << ":";
    fore(x, ans) cout << ' ' << x;
    cout << endl;
    return 0;
}
