/*
繰り返し二乗法

参考
https://math.nakaken88.com/textbook/cp-binary-exponentiation-and-recursive-function/
https://algo-logic.info/calc-pow/
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
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

const ll mod = 1000000007;

// 再帰関数を使う方法
ll modpow(ll x, ll n, ll mod) {
    if (n == 0) {
        return 1;
    }

    ll ret = modpow(x, n / 2, mod);
    if (n % 2 == 0) {
        ret = ret * ret % mod;
    } else {
        ret = (((ret * ret) % mod) * x) % mod;
    }
    return ret;
}

// nを2進数で扱ってビット演算を使う方法
ll modpow2(ll x, ll n, ll mod) {
    ll ret = 1;

    while (n > 0) {
        if (n & 1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }

    return ret;
}

int main() {
    ll m, n, ans;
    in(m, n);

    ans = modpow(m, n, mod);
    out(ans);

    return 0;
}
