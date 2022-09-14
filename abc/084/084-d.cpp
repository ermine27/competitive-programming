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
using ll = long long;
using vi = vector<int>;
template<typename T> T pow2(T x) { return x * x; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

const int CMAX = 1e5 + 2;

vi primes;

// 素数列挙（エラストテネスの篩）
void eratosthenes(int x) {
    primes.resize(x + 1, 1);
    primes[0] = 0;
    primes[1] = 0;

    for (int i = 2; i * i < x; ++i) {
        if (primes[i]) {
            for (int j = i * 2; j <= x; j += i) {
                primes[j] = 0;
            }
        }
    }
}

int main() {
    eratosthenes(CMAX);

    vi likenumber(CMAX);
    rep(i, CMAX) {
        if (primes[i] && primes[(i + 1) / 2]) {
            likenumber[i] = 1;
        }
    }

    vi c(CMAX + 1);
    repe(i, CMAX) {
        c[i] = c[i - 1] + likenumber[i];
    }

    int q, a, b;
    in(q);
    rep(i, q) {
        int ans = 0;
        in(a, b);
        ans = c[b] - c[a - 1];
        out(ans);
    }

    return 0;
}
