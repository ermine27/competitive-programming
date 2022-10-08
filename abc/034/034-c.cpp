/*
参考：二項係数(nCk)を素数(p)で割った余りの計算と逆元のまとめ
https://algo-logic.info/combination/
*/
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
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

const ll mod = 1000000007;

int main() {
    int w, h, s;
    in(w, h);
    --w;
    --h;
    s = w + h;

    // 前処理
    vl fact(s + 1), factinv(s + 1), inv(s + 1);
    fact[0] = fact[1] = 1;
    factinv[0] = factinv[1] = 1;
    inv[1] = 1;
    repe(i, 2, s) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        factinv[i] = factinv[i - 1] * inv[i] % mod;
    }

    // nCkの計算
    // nCk ≡ n! * (k!)^-1 * ((n-k)!)^-1  (mod P)
    ll ans = fact[s] * (factinv[h] * factinv[s - h] % mod) % mod;

    out(ans);
    return 0;
}
