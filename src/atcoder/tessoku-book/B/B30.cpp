#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

int main() {
    const int MOD = 1000000007;
    int h, w, n;
    cin >> h >> w;
    h--;
    w--;
    n = h + w;

    vl fact(n + 1), factinv(n + 1), inv(n + 1);
    fact[0] = fact[1] = 1;
    factinv[0] = factinv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i <= h + w; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        factinv[i] = factinv[i - 1] * inv[i] % MOD;
    }

    ll ans = fact[n] * (factinv[h] * factinv[n - h] % MOD) % MOD;
    cout << ans << endl;
    return 0;
}
